/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_photon_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:03:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:30:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "kdtree.h"
#include "object.h"
#include "photon.h"
#include "vector.h"

static int	fill_photons(t_vector *photons, t_engine *eng, t_light *light);
static int	create_photon_map(t_engine *eng, t_light *light);

int	init_photon_map(t_engine *eng)
{
	size_t		i;
	t_light		*curr;

	init_vector(&eng->caustic_maps, (sizeof(t_kdtree *)));
	i = 0;
	while (i < eng->scene.lights.size)
	{
		curr = at_vector(&eng->scene.lights, i);
		if (create_photon_map(eng, curr) == -1)
		{
			clear_photon_maps(&eng->caustic_maps);
			return (-1);
		}
		++i;
	}
	return (0);
}

static int	create_photon_map(t_engine *eng, t_light *light)
{
	t_vector	photon_map;
	t_kdtree	*root;

	printf("create photon_map\n");
	init_vector(&photon_map, sizeof(t_photon));
	if (fill_photons(&photon_map, eng, light) == -1)
	{
		clear_vector(&photon_map);
		return (-1);
	}
	root = init_kdtree(&photon_map, 0);
	clear_vector(&photon_map);
	if (root == NULL && errno)
	{
		clear_kdtree(root);
		return (-1);
	}
	if (add_vector(&eng->caustic_maps, &root, 1) == -1)
		return (-1);
	return (0);
}

static int	fill_photons(t_vector *photons, t_engine *eng, t_light *light)
{
	size_t		i;
	t_object	*curr;

	i = 0;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == SPHERE
			&& curr->optional_data.material.refract_index)
		{
			if (generate_photons(eng, photons, light) == -1)
				return (-1);
		}
		++i;
	}
	return (0);
}
