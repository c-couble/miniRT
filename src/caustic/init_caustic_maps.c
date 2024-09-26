/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 04:50:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 23:20:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "bounding_box.h"
#include "caustic.h"
#include "engine.h"
#include "kdtree.h"
#include "object.h"
#include "object/light.h"
#include "vector.h"
#include <stdio.h>

static int	init_caustic_map(t_engine *eng, t_light *light, t_object *obj);

int	init_caustic_maps(t_engine *eng, t_caustic *caustic)
{
	size_t		i;
	size_t		j;
	t_light		*lights;
	t_object	*objects;

	dprintf(2, "init caustic maps\n");
	init_vector(&caustic->caustic_maps, sizeof(t_caustic_map));
	lights = eng->scene.lights.array;
	objects = eng->scene.objects.array;
	i = 0;
	while (i < eng->scene.lights.size)
	{
		j = 0;
		while (j < eng->scene.objects.size)
		{
			if (init_caustic_map(eng, &lights[i], &objects[j]) == -1)
			{
				return (-1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

static int	init_caustic_map(t_engine *eng, t_light *light, t_object *obj)
{
	t_vector		photon_map;
	t_caustic_map	map;

	(void)obj;
	if (obj->optional_data.photon_nb == 0)
		return (0);
	dprintf(2, "init caustic map\n");
	init_vector(&photon_map, sizeof(t_photon));
	if (generate_photons(eng, &photon_map, light) == -1)
	{
		clear_vector(&photon_map);
		return (-1);
	}
	get_caustic_aabb(&photon_map, &map.aabb);
	map.tree = init_kdtree(&photon_map, 0);
	clear_vector(&photon_map);
	if (map.tree == NULL && errno)
	{
		clear_kdtree(map.tree);
		return (-1);
	}
	if (add_vector(&eng->caustic.caustic_maps, &map, 1) == -1)
		return (-1);
	return (0);
}
