/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/09 20:13:38 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "shading.h"

t_colorf	shade_ray(t_scene *scene, t_ray *c_ray, int depth)
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
		color = get_direct_lighting(scene, c_ray);
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
