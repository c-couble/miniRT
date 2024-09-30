/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 04:50:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 22:42:15 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "bounding_box.h"
#include "caustic.h"
#include "kdtree.h"
#include "object.h"
#include "object/light.h"
#include "scene.h"
#include "vector.h"
#include <stdio.h>

static int	init_caustic_map(t_scene *scene, t_light *light, t_object *obj);

int	init_caustic_maps(t_scene *scene, t_caustic *caustic)
{
	size_t		i;
	size_t		j;
	t_light		*lights;
	t_object	*objects;

	(void)caustic;
	lights = scene->lights.array;
	objects = scene->objects.array;
	i = 0;
	while (i < scene->lights.size)
	{
		j = 0;
		while (j < scene->objects.size)
		{
			if (init_caustic_map(scene, &lights[i], &objects[j]) == -1)
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

static int	init_caustic_map(t_scene *scene, t_light *light, t_object *obj)
{
	t_vector		photon_map;
	t_caustic_map	map;

	if (obj->optional_data.photon_nb == 0)
		return (0);
	dprintf(2, "init caustic map\n");
	init_vector(&photon_map, sizeof(t_photon));
	if (get_photons(scene, &photon_map, obj, light) == -1)
	{
		clear_vector(&photon_map);
		return (-1);
	}
	get_caustic_aabb(&photon_map, &map.aabb);
	dprintf(2, "photon nb = %ld\n", photon_map.size);
	map.tree = init_kdtree(&photon_map, 0);
	clear_vector(&photon_map);
	if ((map.tree == NULL && errno)
		|| add_vector(&scene->caustic.caustic_maps, &map, 1) == -1)
	{
		clear_kdtree(map.tree);
		return (-1);
	}
	return (0);
}
