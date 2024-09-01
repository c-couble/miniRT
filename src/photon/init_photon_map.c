/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_photon_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:03:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/01 05:24:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <math.h>
#include "defines.h"
#include "object.h"
#include "util.h"

static int	fill_photons(t_vector *photons, t_engine *eng, t_light *light);
static int	generate_photons(t_engine *eng, t_vector *photons, t_light *light);
static void	generate_spherical_ray(t_vec3 *dir);

int	init_photon_map(t_engine *eng)
{
	size_t		i;
	t_object	*curr;
	t_vector	photon_map;

	init_vector(&photon_map, sizeof(t_photon));
	i = 0;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == LIGHT)
		{
			if (fill_photons(&photon_map, eng,
					(t_light *)&curr->data.light) == -1)
			{
				clear_vector(&photon_map);
				return (-1);
			}
		}
		++i;
	}
	eng->node = init_kdtree(&photon_map, 0);
	clear_vector(&photon_map);
	if (eng->node == NULL && errno)
	{
		clear_kdtree(eng->node);
		return (-1);
	}
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
			&& curr->optional_data.material.refraction_ratio)
		{
			if (generate_photons(eng, photons, light) == -1)
				return (-1);
		}
		++i;
	}
	return (0);
}

static int	generate_photons(t_engine *eng, t_vector *photons, t_light *light)
{
	size_t		j;
	t_photon	photon;
	t_ray		p_ray;

	j = 0;
	while (j < PHOTON_PER_OBJ)
	{
		generate_spherical_ray(&p_ray.ray);
		vec3_normalize(&p_ray.ray);
		p_ray.startpos = light->pos;
		if (trace_photon(eng, &p_ray, DEPTH, &photon))
		{
			photon.color.color = light->color.color;
			photon.ratio = light->ratio;
			if (add_vector(photons, &photon, 1) == -1)
				return (-1);
		}
		++j;
	}
	return (0);
}

static void	generate_spherical_ray(t_vec3 *dir)
{
	const double	phi = rand_range(0.0, 2.0 * M_PI);
	const double	cos_theta = rand_range(-1, 1);
	const double	sin_theta = sqrt(1 - cos_theta * cos_theta);

	dir->x = sin_theta * cos(phi);
	dir->y = sin_theta * sin(phi);
	dir->z = cos_theta;
}
