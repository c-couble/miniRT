/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 05:35:38 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "defines.h"
#include "object/camera.h"
#include "shading.h"

uint32_t	get_pixel_color(t_engine *engine, t_ray *c_ray, int depth)
{
	t_color	color;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
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
		if (engine->scene.camera.render_type == NORMAL)
			return (get_normal_color(c_ray));
		return (color.color);
	}
	return (BACKGROUND_COLOR);
}
