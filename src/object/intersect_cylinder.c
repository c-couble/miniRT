/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/06 19:27:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "math_util.h"
#include "object.h"
#include "ray.h"
#include "vector3d.h"
#include <math.h>

static double	hit_cyl(t_object *obj, t_ray *ray);
static double	check_disk(t_object *obj, t_ray *ray, t_vector3d *p);

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	double	cyl_t = hit_cyl(obj, ray);

	t_vector3d	a = obj->data.cylinder.axis;
	vector_multiply_coeff(&a, obj->data.cylinder.height / 2);
	t_vector3d	r2;
	r2 = obj->data.cylinder.coordinates;
	vector_addition(&r2, &a);

	t_vector3d	r1;
	vector_subtract(&obj->data.cylinder.coordinates, &a, &r1);
	double t = check_disk(obj, ray, &r1);
	double t2 = check_disk(obj, ray, &r2);

	if (cyl_t == -1 && t == -1)
		return (t2);
	if (cyl_t == -1 && t2 == -1)
		return (t);
	if (t == -1 && t2 == -1)
		return (cyl_t);
	if (cyl_t == -1)
	{
		if (t > t2)
			return (t2);
		return (t);
	}
	if (t == -1)
	{
		if (cyl_t > t2)
			return (t2);
		return (cyl_t);
	}
	if (t2 == -1)
	{
		if (cyl_t > t)
			return (t);
		return (cyl_t);
	}
	if (cyl_t < t && cyl_t < t2)
		return (cyl_t);
	if (t < cyl_t && t < t2)
		return (t);
	if (t2 < t && t2 < cyl_t)
		return (t2);
	return (-1);
}

static double	check_disk(t_object *obj, t_ray *ray, t_vector3d *p)
{
	double dot_ray_n = vector_dot_product(&ray->ray, &obj->data.plane.orientation);
	if (dot_ray_n == 0)
		return (-1);
	double ax = obj->data.cylinder.axis.x * p->x;
	double by = obj->data.cylinder.axis.y * p->y;
	double cz = obj->data.cylinder.axis.z * p->z;
	double d = -(ax + by + cz);

	ax = obj->data.cylinder.axis.x * ray->startpos.x;
	by = obj->data.cylinder.axis.y * ray->startpos.y;
	cz = obj->data.cylinder.axis.z * ray->startpos.z;
	double t = (-(ax + by + cz + d)) / dot_ray_n;
	if (t <= INACCURATE_ZERO || t >= ray->maxlen - 1)
		return (-1);
	t_vector3d bolide;
	t_vector3d bolide2;
	bolide = ray->ray;
	vector_multiply_coeff(&bolide, t);
	bolide2.x = ray->startpos.x + bolide.x;
	bolide2.y = ray->startpos.y + bolide.y;
	bolide2.z = ray->startpos.z + bolide.z;
	bolide2.x = p->x - bolide2.x;
	bolide2.y = p->y - bolide2.y;
	bolide2.z = p->z - bolide2.z;
	if (vector_get_norm(&bolide2) < powl(obj->data.cylinder.diameter / 2, 2))
		return (t);
	return (-1);
}

static double	hit_cyl(t_object *obj, t_ray *ray)
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
