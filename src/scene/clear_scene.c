/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:40:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:33:50 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "object.h"
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
}

static void	clear_object(t_object *obj)
{
	if (obj->type == MESH)
		free(obj->data.mesh.cache);
}
