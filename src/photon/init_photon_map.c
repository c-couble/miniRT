/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_photon_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:03:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/19 15:51:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object.h"
#include "photon.h"
#include "vec3.h"
#include "vector.h"
#include <stdio.h>

static int	get_photon(t_engine *eng, t_light *light);

int	init_photon_map(t_engine *eng)
{
	size_t		i;
	t_object	*curr;

	dprintf(2, "Init photon map\n");
	init_vector(&eng->photon_map, sizeof(t_photon));
	i = 0;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == LIGHT)
		{
			if (get_photon(eng, (t_light *)&curr->data.light) == -1)
				return (-1);
		}
		++i;
	}
	printf("non sorted\n");
	print_photon_map(eng);
	printf("sorted\n");
	sort_photons_axis(&eng->photon_map, 0, eng->photon_map.size - 1, 2);
	print_photon_map(eng);
	return (0);
}

static int	get_photon(t_engine *eng, t_light *light)
{
	size_t		i;
	t_object	*curr;
	t_photon	photon;
	t_ray		p_ray;

	i = 0;
	photon.color.color = 15510;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == SPHERE && curr->material.refraction_ratio)
		{
			int i = 0;
			while (i < PHONTON_PER_OBJ)
			{
				p_ray.startpos = light->pos;
				vec3_subtract(&curr->data.sphere.pos, &p_ray.startpos, &p_ray.ray);
				vec3_normalize(&p_ray.ray);
				vec3_random(&p_ray.ray, 1.0, 1.20);
				if (trace_photon(eng, &p_ray, DEPTH, &photon))
				{
					photon.color.color = light->color.color;
					dprintf(2, "Added photon, obj type == %d\n", curr->type);
					if (add_vector(&eng->photon_map, &photon, 1) == -1)
						return (-1);
				}
					++i;
			}
		}
		++i;
	}
	return (0);
}
