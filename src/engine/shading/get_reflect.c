/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:05:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/24 00:59:43 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading.h"
#include "color_util.h"

uint32_t	get_reflect(t_engine *eng, t_ray *c_ray, t_color color, int depth)
{
	t_ray	reflection_ray;
	t_color	ref;

	get_reflection_ray(c_ray, c_ray, &reflection_ray.ray);
	reflection_ray.startpos = c_ray->data.hitpos;
	ref.color = get_pixel_color(eng, &reflection_ray, depth);
	ref.color = scale_color(&ref, c_ray->data.materials.reflect_ratio);
	color.color = scale_color(&color, 1 - c_ray->data.materials.reflect_ratio);
	color.color = add_color(&color, &ref);
	return (color.color);
}
