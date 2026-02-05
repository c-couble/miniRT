/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:17:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "object/camera.h"
#include "shading.h"

//TODO finish wrapper

uint32_t	get_color(t_scene *scene, t_ray *c_ray, int depth)
{
	t_colorf	n_color;

	n_color = get_pixel_color(scene, c_ray, depth);
	return (color_denormalize(n_color));
}

t_colorf	get_pixel_color(t_scene *scene, t_ray *c_ray, int depth)
{
	t_colorf	color;

	if (depth <= 0)
		return (scene->background);
	if (trace_ray(scene, c_ray) > -INACCURATE_ZERO)
	{
		if (scene->camera.render_type == NORMAL)
			return (get_normal_color(c_ray));
		if (scene->camera.render_type == UV_MAP)
			return (get_uv_color(c_ray));
		color = get_light(scene, c_ray);
		if (c_ray->data.materials->refract_index
			&& c_ray->data.materials->reflect_ratio)
			color = get_fresnel(scene, c_ray, color, depth -1);
		else if (c_ray->data.materials->reflect_ratio)
			color = get_reflect(scene, c_ray, color, depth -1);
		else if (c_ray->data.materials->refract_index)
			color = get_refract(scene, c_ray, color, depth -1);
		return (color);
	}
	return (scene->background);
}
