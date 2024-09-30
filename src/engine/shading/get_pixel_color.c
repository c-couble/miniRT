/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 08:43:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "object/camera.h"
#include "shading.h"

uint32_t	get_pixel_color(t_scene *scene, t_ray *c_ray, int depth)
{
	t_color	color;

	if (depth <= 0)
		return (scene->background.color);
	if (trace_ray(scene, c_ray) > -INACCURATE_ZERO)
	{
		if (scene->camera.render_type == NORMAL)
			return (get_normal_color(c_ray));
		if (scene->camera.render_type == UV_MAP)
			return (get_uv_color(c_ray));
		color.color = get_light(scene, c_ray);
		if (c_ray->data.materials->refract_index
			&& c_ray->data.materials->reflect_ratio)
			get_fresnel(scene, c_ray, &color, depth -1);
		else if (c_ray->data.materials->reflect_ratio)
			color.color = get_reflect(scene, c_ray, color, depth -1);
		else if (c_ray->data.materials->refract_index)
			color.color = get_refract(scene, c_ray, color, depth -1);
		return (color.color);
	}
	return (scene->background.color);
}
