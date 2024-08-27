/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 05:18:19 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading.h"
#include "defines.h"

uint32_t	get_pixel_color(t_engine *engine, t_ray *c_ray, int depth)
{
	t_color	color;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
	c_ray->depth = depth;
	if (trace_ray(engine, c_ray) > -INACCURATE_ZERO)
	{
		color.color = get_light(engine, c_ray);
		if (c_ray->data.materials.refraction_ratio
			&& c_ray->data.materials.reflect_ratio)
			get_fresnel(engine, c_ray, &color, depth -1);
		else if (c_ray->data.materials.reflect_ratio)
			color.color = get_reflect(engine, c_ray, color, depth -1);
		else if (c_ray->data.materials.refraction_ratio)
			color.color = get_refract(engine, c_ray, color, depth -1);
		return (color.color);
	}
	return (BACKGROUND_COLOR);
}
