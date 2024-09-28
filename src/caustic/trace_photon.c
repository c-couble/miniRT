/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_photon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:12:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 22:00:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "shading.h"

static void	set_refract_photon(t_ray *ph_ray, t_ray *refr, t_photon *ph);

int	trace_photon(t_scene *scene, t_ray *ph_ray, int depth, t_photon *ph)
{
	t_ray	refract_ray;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
	if (trace_ray(scene, ph_ray) > INACCURATE_ZERO)
	{
		if (ph_ray->data.materials->refract_index)
		{
			set_refract_photon(ph_ray, &refract_ray, ph);
			return (trace_photon(scene, &refract_ray, depth -1, ph));
		}
		if (depth == DEPTH)
			return (0);
		ph->pos = ph_ray->data.hitpos;
		return (1);
	}
	return (0);
}

static void	set_refract_photon(t_ray *ph_ray, t_ray *refr, t_photon *ph)
{
	t_color	refract;

	if (ph_ray->data.materials->refract_blend != 1)
	{
		refract.color = scale_color(&ph_ray->data.color,
				1 - ph_ray->data.materials->refract_blend);
		ph->color.color = multiply_color(&refract, &ph->color);
	}
	get_refraction_ray(ph_ray, &refr->ray,
		ph_ray->data.materials->refract_index);
	refr->startpos = ph_ray->data.hitpos;
}
