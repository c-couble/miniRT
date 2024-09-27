/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:36:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:21:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shading.h"

uint32_t	get_refract(t_scene *scene, t_ray *c_ray, t_color color, int depth)
{
	t_ray	refract_ray;
	t_color	refract;

	get_refraction_ray(c_ray, &refract_ray.ray,
		c_ray->data.materials.refract_index);
	get_inv_dir(&refract_ray);
	refract_ray.startpos = c_ray->data.hitpos;
	refract.color = get_pixel_color(scene, &refract_ray, depth);
	refract.color = scale_color(&refract, c_ray->data.materials.refract_blend);
	color.color = scale_color(&color, 1 - c_ray->data.materials.refract_blend);
	color.color = add_color(&color, &refract);
	return (color.color);
}
