/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:36:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/18 10:17:04 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "color_util.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "vec3.h"

t_vec3	get_refraction_ray(t_ray *to_ref, t_ray *camera_ray, double n1, double n2)
{
	double		n = n1 / n2;
	t_vec3		e = to_ref->ray;
	double		dot_E_N;
	t_vec3		object_n;
	t_vec3		refraction;

	vec3_scale(&e, -1);
	object_n = camera_ray->data.normal;
	dot_E_N = vec3_dot_product(&e, &object_n);
	double res = n * dot_E_N - sqrt(1 - n * n * (1 - dot_E_N * dot_E_N));
	vec3_scale(&e, n);
	vec3_scale(&object_n, res);
	vec3_add(&object_n, &e, &refraction);
	return (refraction);
}

void	get_refract(t_engine *engine, t_ray *c_ray, t_ray *to_ref, int depth)
{
	t_ray	r_ray;
	double	d;
	t_ray	r_ray2;

	if (depth <= 0)
		return ;
	r_ray.startpos = to_ref->data.hitpos;
	r_ray.ray = get_refraction_ray(to_ref, to_ref, AIR_RATIO, GLASS_RATIO);
	vec3_scale(&r_ray.ray, -1);
	vec3_normalize(&r_ray.ray);
	d = trace_ray(engine, &r_ray);
	if (d > -INACCURATE_ZERO && r_ray.data.ptr->type == SPHERE)
	{
		r_ray2.ray = get_refraction_ray(to_ref, to_ref, AIR_RATIO, GLASS_RATIO);
		r_ray2.startpos = r_ray.data.hitpos;
		vec3_scale(&r_ray2.ray, -1);
		vec3_normalize(&r_ray2.ray);
		d = trace_ray(engine, &r_ray2);
		if (d > -INACCURATE_ZERO && r_ray2.data.ptr->type == SPHERE)
			get_refract(engine, c_ray, &r_ray2, depth - 1);
		else if (d > -INACCURATE_ZERO)
		{
			c_ray->data.color.color = get_light(engine, &r_ray2);
		}
	}
	else if (d > -INACCURATE_ZERO)
	{
			c_ray->data.color.color = get_light(engine, &r_ray);
	}
	return ;
}
