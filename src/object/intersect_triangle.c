/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/28 04:47:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "ray.h"
#include "object.h"
#include "defines.h"
#include <unistd.h>

double	intersect_triangle(t_object *obj, t_ray *ray)
{
	t_vec3	O = ray->startpos;
	t_vec3	D = ray->ray;
	t_vec3	T;
	t_vec3	E1;
	t_vec3	E2;
	t_vec3	P;
	t_vec3	Q;

	vec3_subtract(&O, &obj->data.triangle.p0, &T);
	vec3_subtract(&obj->data.triangle.p1, &obj->data.triangle.p0, &E1);
	vec3_subtract(&obj->data.triangle.p2, &obj->data.triangle.p0, &E2);
	vec3_cross_product(&D, &E2, &P);
	vec3_cross_product(&T, &E1, &Q);
	double inv_det = 1 / vec3_dot_product(&P, &E1);
	double u = inv_det * vec3_dot_product(&P, &T);
	if (u < 0 || u > 1)
		return (-1);
	double v = inv_det * vec3_dot_product(&Q, &D);
	if (v < 0 || u + v > 1)
		return (-1);
	double t = inv_det * vec3_dot_product(&Q, &E2);
	if (t < INACCURATE_ZERO)
		return (-1);

	//ray->data.color = obj->data.triangle.color;

	//ray->data.color.rgb.r = u * 255;
	//ray->data.color.rgb.g = v * 255;
	//ray->data.color.rgb.b = (1 - u - v) * 255;
	vec3_cross_product(&E1, &E2, &ray->data.normal);
	vec3_normalize(&ray->data.normal);
	ray->data.color.rgb.r = (ray->data.normal.x + 1) * 0.5 * 255;
	ray->data.color.rgb.g = (ray->data.normal.y + 1) * 0.5 * 255;
	ray->data.color.rgb.b = (ray->data.normal.z + 1) * 0.5 * 255;
	//vec3_normalize(&normal);
	return (t);
}
