/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_photon_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:03:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/31 04:20:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include "engine.h"
#include "kdtree.h"
#include "object.h"
#include "photon.h"
#include "vec3.h"
#include "vector.h"
#include "defines.h"

static int	get_photon(t_vector *photons, t_engine *eng, t_light *light);

int	init_photon_map(t_engine *eng)
{
	size_t		i;
	t_object	*curr;
	t_vector	photon_map;

	dprintf(2, "Init photon map\n");
	init_vector(&photon_map, sizeof(t_photon));
	i = 0;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == LIGHT)
		{
			if (get_photon(&photon_map, eng, (t_light *)&curr->data.light) == -1)
				return (-1);
		}
		++i;
	}
	sort_photons_axis(&photon_map, 0, photon_map.size - 1, 1);
	print_photon_map(&photon_map);
	eng->node = init_kdtree(&photon_map, 0);
	//clear_vector(&photon_map);
	if (eng->node == NULL && errno)
	{
		clear_kdtree(eng->node);
		return (-1);
	}
	print_kdtree(eng->node, 0);
	return (0);
}
#include "stdlib.h"
static double	randf_range(double min, double max)
{
	double	range;
	double	div;

	range = (max - min);
	div = RAND_MAX / range;
	return (min + (rand() / div));
}

static int	get_photon(t_vector *photons, t_engine *eng, t_light *light)
{
	size_t		i;
	t_object	*curr;
	t_photon	photon;
	t_ray		p_ray;
	t_vec3		dir;

	i = 0;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == SPHERE && curr->material.refraction_ratio)
		{
			int i = 0;
			while (i < PHOTON_PER_OBJ)
			{
				double phi = randf_range(0.0, 2.0 * M_PI);
				double cos_theta = randf_range(-1, 1);
				double sin_theta = sqrt(1 - cos_theta * cos_theta);

				p_ray.ray.x = sin_theta * cos(phi);
				p_ray.ray.y = sin_theta * sin(phi);
				p_ray.ray.z = cos_theta;
				vec3_subtract(&curr->data.sphere.pos, &p_ray.startpos, &dir);
				vec3_normalize(&p_ray.ray);
				//vec3_random(&p_ray.ray, 1.0, 1.60);
				if (trace_photon(eng, &p_ray, DEPTH, &photon))
				{
					photon.color.color = light->color.color;
//					dprintf(2, "Added photon, obj type == %d\n", curr->type);
					if (add_vector(photons, &photon, 1) == -1)
						return (-1);
				}
				++i;
			}
		}
		++i;
	}
	return (0);
}
