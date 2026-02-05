/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:36:17 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:18:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shading.h"

t_colorf	get_refract(t_scene *scene, t_ray *c_ray, t_colorf color, int depth)
{
	t_ray		refract_ray;
	t_colorf	refract;

	get_refraction_ray(c_ray, &refract_ray.ray,
		c_ray->data.materials->refract_index);
	get_inv_dir(&refract_ray);
	refract_ray.startpos = c_ray->data.hitpos;
	refract_ray.t_id = c_ray->t_id;
	refract = get_pixel_color(scene, &refract_ray, depth);
	refract = color_scale(refract, c_ray->data.materials->refract_blend);
	color = color_scale(color, 1 - c_ray->data.materials->refract_blend);
	color = color_add(color, refract);
	return (color);
}
