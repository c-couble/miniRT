/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 09:46:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "color_util.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"

uint32_t	get_pixel_color(t_engine *engine, t_ray *c_ray, int depth)
{
	t_color	color;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
	if (trace_ray(engine, c_ray) > -INACCURATE_ZERO)
	{
		//camera_ray.data.color.color = get_normal_color(&camera_ray);
		color.color = get_light(engine, c_ray);
		if (c_ray->data.materials.reflect_ratio > 0)
			color.color = get_reflect(engine, c_ray, color, depth -1);
		if (c_ray->data.materials.refraction_ratio)
			color.color = get_refract(engine, c_ray, color, depth -1);
		return (color.color);
	}
	return (BACKGROUND_COLOR);
}
