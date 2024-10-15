/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_objects_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:50:53 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 15:02:40 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"

static void	clear_object(t_object *obj);

void	clear_objects_vectors(t_scene *scene)
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
}

static void	clear_object(t_object *obj)
{
	if (obj->type == MESH)
	{
		clear_bvh_tree(obj->data.mesh.bvh);
		free(obj->data.mesh.cache);
	}
}
