/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:40:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 07:23:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "object.h"
#include "bvh.h"
#include "scene.h"

static void	clear_object(t_object *obj);

void	clear_scene(t_scene *scene)
{
	t_object	*obj;
	size_t		i;

	i = 0;
	while (i < scene->objects.size)
	{
		obj = at_vector(&scene->objects, i);
		clear_object(obj);
		++i;
	}
	clear_vector(&scene->objects);
	clear_vector(&scene->lights);
	clear_vector(&scene->planes);
	clear_bvh(&scene->bvh);
	clear_caustic(&scene->caustic);
}

static void	clear_object(t_object *obj)
{
	if (obj->type == MESH)
		free(obj->data.mesh.cache);
}
