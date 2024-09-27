/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:36:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:05:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shading.h"

uint32_t	get_refract(t_scene *scene, t_ray *c_ray, t_color color, int depth)
{
	t_ray	refract_ray;
	t_color	refract_color;

	get_refraction_ray(c_ray, &refract_ray.ray,
		c_ray->data.materials.refraction_ratio);
	get_inv_dir(&refract_ray);
	refract_ray.startpos = c_ray->data.hitpos;
	refract_color.color = get_pixel_color(scene, &refract_ray, depth);
	color.color = refract_color.color;
	return (color.color);
}
