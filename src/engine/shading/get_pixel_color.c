/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 19:58:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "object/camera.h"
#include "shading.h"

uint32_t	get_pixel_color(t_engine *engine, t_ray *c_ray, int depth)
{
	t_color	color;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
	if (trace_ray2(engine, c_ray) > -INACCURATE_ZERO)
	{
		if (engine->scene.camera.render_type == NORMAL)
			return (get_normal_color(c_ray));
		if (engine->scene.camera.render_type == UV_MAP)
			return (get_uv_color(c_ray));
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
