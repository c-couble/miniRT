/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_photons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:28:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/25 06:45:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "defines.h"
#include "object/light.h"
#include "photon.h"
#include "ray.h"
#include "util.h"
#include "vector.h"

void	generate_spherical_ray(t_vec3 *dir);

int	generate_photons(t_engine *eng, t_vector *photons, t_light *light)
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
		get_inv_dir(&p_ray);
		photon.color.color = light->color.color;
		photon.ratio = light->ratio;
		if (trace_photon(eng, &p_ray, DEPTH, &photon))
		{
			if (add_vector(photons, &photon, 1) == -1)
				return (-1);
		}
		++j;
	}
	return (0);
}

void	generate_spherical_ray(t_vec3 *dir)
{
	const double	phi = rand_range(0.0, 2.0 * M_PI);
	const double	cos_theta = rand_range(-1, 1);
	const double	sin_theta = sqrt(1 - cos_theta * cos_theta);

	dir->x = sin_theta * cos(phi);
	dir->y = sin_theta * sin(phi);
	dir->z = cos_theta;
}
