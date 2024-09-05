/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/05 02:52:34 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include "defines.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

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
	vec3_cross(&D, &E2, &P);
	vec3_cross(&T, &E1, &Q);
	double dot = vec3_dot(&P, &E1);
	if (double_equals(dot, 0))
		return (-1);
	double inv_det = 1 / dot;
	double u = inv_det * vec3_dot(&P, &T);
	if (u < 0 || u > 1)
		return (-1);
	double v = inv_det * vec3_dot(&Q, &D);
	if (v < 0 || u + v > 1)
		return (-1);
	double t = inv_det * vec3_dot(&Q, &E2);
	if (t < INACCURATE_ZERO)
		return (-1);

	vec3_cross(&E1, &E2, &ray->data.normal);
	vec3_normalize(&ray->data.normal);
	ray->data.u = (1 - u - v) * obj->data.triangle.p0t.x
		+ u * obj->data.triangle.p1t.x
		+ v * obj->data.triangle.p2t.x;
	ray->data.v = (1 - u - v) * obj->data.triangle.p0t.y
		+ u * obj->data.triangle.p1t.y
		+ v * obj->data.triangle.p2t.y;
	ray->data.u = fabs(fmod(ray->data.u, 1));
	ray->data.v = fabs(fmod(ray->data.v, 1));
	ray->data.texture = obj->data.triangle.texture;
	//vec3_normalize(&normal);
	return (t);
}
