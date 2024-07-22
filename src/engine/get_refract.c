/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:36:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 04:30:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "color_util.h"
#include "defines.h"
#include "vec3.h"
#include "util.h"

int	get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1)
{
	double		n;
	t_vec3		e = to_ref->ray;
	double		dot_e_n;
	t_vec3		object_n;
	double 		to_sqrt;
	double 		n0 = AIR_RATIO;
	double 		n3 = n1;

	object_n = to_ref->data.normal;
	dot_e_n = vec3_dot_product(&e, &object_n);
	// outside of the surface
	if (dot_e_n < 0)
		dot_e_n = -dot_e_n;
	// inside of the surface
	else 
	{
		vec3_scale(&object_n, -1);
		ft_dswap(&n0, &n3);
	}
	n = n0 / n3;
	to_sqrt = 1 - n * n * (1 - dot_e_n * dot_e_n);
	if (to_sqrt < 0)
		return (-1);
	double res = n * dot_e_n - sqrt(to_sqrt);
	vec3_scale(&e, n);
	vec3_scale(&object_n, res);
	vec3_add(&object_n, &e, out_ref);
	return (0);
}

void	get_refract(t_engine *engine, t_ray *c_ray, t_ray *to_ref, int depth, double n1)
{
	t_ray	r_ray;
	double	d;

	if (depth <= 0)
		return ;
	r_ray.startpos = to_ref->data.hitpos;
	if (get_refraction_ray(to_ref, &r_ray.ray, n1) == -1)
	{
		printf("singe\n");
		get_reflection_ray(to_ref, to_ref, &r_ray.ray);
	}
	vec3_normalize(&r_ray.ray);
	d = trace_ray(engine, &r_ray);
	if (d > -INACCURATE_ZERO && r_ray.data.obj_material.refraction_ratio)
	{
		get_refract(engine, c_ray, &r_ray, depth - 1,
			  r_ray.data.obj_material.refraction_ratio);
	}
	else if (d > -INACCURATE_ZERO)
	{
		if (r_ray.data.obj_material.reflect_ratio)
			get_reflect(engine, c_ray, &r_ray, DEPTH);
		else
			c_ray->data.color.color = get_light(engine, &r_ray);
	}
	return ;
}
