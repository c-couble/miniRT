/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_photons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:28:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/10/14 06:22:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "caustic.h"
#include "defines.h"
#include "object.h"
#include "photon.h"
#include "ray.h"
#include "scene.h"
#include "util.h"
#include "vector.h"

static void	generate_spherical_ray(t_ray *ray);

int	get_photons(t_scene *scene, t_vector *p, t_object *obj, t_light *light)
{
	int			i;
	t_photon	photon;
	t_ray		p_ray;

	i = 0;
	while (i < obj->optional_data.photon_nb)
	{
		generate_spherical_ray(&p_ray);
		p_ray.startpos = light->pos;
		photon.color.color = scale_color(&light->color, 1.0);
		photon.ratio = light->ratio;
		if (intersect(obj, &p_ray) > INACCURATE_ZERO)
		{
			if (trace_photon(scene, &p_ray, DEPTH, &photon))
			{
				if (add_vector(p, &photon, 1) == -1)
					return (-1);
			}
			if (FORCE_P_RAY)
				++i;
		}
		if (FORCE_P_RAY == 0)
			++i;
	}
	return (0);
}

static void	generate_spherical_ray(t_ray *ray)
{
	const double	phi = rand_range(0.0, 2.0 * M_PI);
	const double	cos_theta = rand_range(-1, 1);
	const double	sin_theta = sqrt(1 - cos_theta * cos_theta);

	ray->ray.x = sin_theta * cos(phi);
	ray->ray.y = sin_theta * sin(phi);
	ray->ray.z = cos_theta;
	vec3_normalize(&ray->ray);
	get_inv_dir(ray);
}
