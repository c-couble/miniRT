/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:05:00 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 00:32:15 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ray.h"
#include "shading.h"
#include "vec3.h"

t_colorf	get_reflect(t_scene *scene, t_ray *c_ray, t_colorf color, int depth)
{
	t_ray		reflection_ray;
	t_colorf	ref;

	get_reflection_ray(c_ray, c_ray, &reflection_ray.ray);
	get_inv_dir(&reflection_ray);
	reflection_ray.startpos = c_ray->data.hitpos;
	reflection_ray.t_id = c_ray->t_id;
	(void)scene;
	(void)depth;
	// ref.color = get_pixel_color(scene, &reflection_ray, depth);
	ref = get_pixel_color(scene, &reflection_ray, depth);
	// ref.color = scale_color(&ref, c_ray->data.materials->reflect_ratio);
	ref = color_scale(ref, c_ray->data.materials->reflect_ratio);
	// color.color = scale_color(&color, 1 - c_ray->data.materials->reflect_ratio);
	color = color_scale(color, 1 - c_ray->data.materials->reflect_ratio);
	// color.color = add_color(&color, &ref);
	color = color_add(color, ref);
	return (color);
}
