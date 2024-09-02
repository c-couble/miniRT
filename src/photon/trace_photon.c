/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_photon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:12:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/02 02:29:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "photon.h"
#include "ray.h"
#include "shading.h"

int	trace_photon(t_engine *engine, t_ray *ph_ray, int depth, t_photon *ph)
{
	t_ray	refract_ray;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
	if (trace_ray(engine, ph_ray) > -INACCURATE_ZERO)
	{
		if (ph_ray->data.materials.refract_index)
		{
			get_refraction_ray(ph_ray, &refract_ray.ray,
				ph_ray->data.materials.refract_index);
			refract_ray.startpos = ph_ray->data.hitpos;
			return (trace_photon(engine, &refract_ray, depth -1, ph));
		}
		ph->pos = ph_ray->data.hitpos;
		return (1);
	}
	return (0);
}
