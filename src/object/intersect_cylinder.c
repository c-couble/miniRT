/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/05 06:08:31 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "math_util.h"
#include "object.h"
#include "ray.h"
#include "vector3d.h"
#include <math.h>

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	ray->color = obj->data.cylinder.color;
	t_vector3d	a = obj->data.cylinder.axis;
	vector_multiply_coeff(&a, obj->data.cylinder.height / 2);
	t_vector3d	r2;
	r2 = obj->data.cylinder.coordinates;
	vector_addition(&r2, &a);

	t_vector3d	r1;
	vector_subtract(&obj->data.cylinder.coordinates, &a, &r1);
	t_vector3d	var1;
	vector_subtract(&ray->startpos, &r1, &var1);

	t_vector3d	a0;
	a0 = obj->data.cylinder.axis;
	vector_cross_product(&obj->data.cylinder.axis, &var1, &a0);
	vector_cross_product(&a0, &obj->data.cylinder.axis, &a0);

	t_vector3d	va;
	vector_cross_product(&obj->data.cylinder.axis, &ray->ray, &va);
	vector_cross_product(&va, &obj->data.cylinder.axis, &va);
	q.a = vector_dot_product(&va, &va);
	q.c = (vector_dot_product(&a0, &a0) - powl(obj->data.cylinder.height / 2, 2));
	vector_multiply_coeff(&a0, 2);
	q.b = vector_dot_product(&a0, &va);

	solve_quadratic_equation(&q);
	if (q.delta >= 0)
	{
		t_vector3d	rray;
		rray = ray->startpos;
		t_vector3d	rayt;
		rayt = ray->ray;
		vector_multiply_coeff(&rayt, q.r1);
		vector_addition(&rray, &rayt);
		t_vector3d	cmp;
		int	r1ok = 1;
		vector_subtract(&rray, &r1, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) <= 0)
			r1ok = 0;
		vector_subtract(&rray, &r2, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) >= 0)
			r1ok = 0;
		rray = ray->startpos;
		rayt = ray->ray;
		vector_multiply_coeff(&rayt, q.r2);
		vector_addition(&rray, &rayt);
		int	r2ok = 1;
		vector_subtract(&rray, &r1, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) <= 0)
			r2ok = 0;
		vector_subtract(&rray, &r2, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) >= 0)
			r2ok = 0;
		if (r1ok && r2ok)
		{
			double	t;
			if (q.r1 <= INACCURATE_ZERO || q.r1 > ray->maxlen)
				t = q.r2;
			else if (q.r2 <= INACCURATE_ZERO || q.r2 > ray->maxlen)
				t = q.r1;
			else
			{
				if (q.r1 > q.r2)
					t = q.r2;
				else
					t = q.r1;
			}
			if (t <= INACCURATE_ZERO || t > ray->maxlen)
				return (-1);
			return (t);
		}
		else if (r1ok)
		{
			if (q.r1 <= INACCURATE_ZERO || q.r1 > ray->maxlen)
				return (-1);
			return (q.r1);
		}
		else if (r2ok)
		{
			if (q.r2 <= INACCURATE_ZERO || q.r2 > ray->maxlen)
				return (-1);
			return (q.r2);
		}
	}
	return (-1);
}
