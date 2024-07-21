/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:05:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/21 19:55:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "color_util.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "vec3.h"

void	get_reflect(t_engine *engine, t_ray *c_ray, t_ray *to_ref, int depth)
{
	t_ray	r_ray;
	t_color r_color;
	double	d;

	if (depth <= 0)
	{
		c_ray->data.color.color = 0;
		return ;
	}
	r_ray.startpos = to_ref->data.hitpos;
	r_ray.ray = get_reflection_ray(to_ref, to_ref);
//	vec3_scale(&r_ray.ray, -1);
	vec3_normalize(&r_ray.ray);
	d = trace_ray(engine, &r_ray);
	if (d > -INACCURATE_ZERO)
	{
		r_color.color = get_light(engine, &r_ray);
		c_ray->data.color.color = scale_color(&c_ray->data.color, 1
										- to_ref->data.obj_material.reflect_ratio);
		r_color.color = scale_color(&r_color, to_ref->data.obj_material.reflect_ratio);
		c_ray->data.color.color = add_color(&r_color, &c_ray->data.color);
		if (r_ray.data.obj_material.reflect_ratio > 0)
			get_reflect(engine, c_ray, &r_ray, depth - 1);
		else if (r_ray.data.obj_material.refraction_ratio >= 1)
		{
			get_refract(engine, c_ray, &r_ray, DEPTH, 
			   r_ray.data.obj_material.refraction_ratio);
		}
	}
	else
	{
		r_color.color = BACKGROUND_COLOR;
		c_ray->data.color.color = scale_color(&c_ray->data.color, 1 -
										to_ref->data.obj_material.reflect_ratio);
		c_ray->data.color.color = get_light(engine, c_ray);
		r_color.color = scale_color(&r_color, to_ref->data.obj_material.reflect_ratio);
		c_ray->data.color.color = add_color(&r_color, &c_ray->data.color);
	}
	return ;
}
