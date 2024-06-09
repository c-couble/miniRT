/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/09 19:13:02 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "math_util.h"
#include "object.h"
#include "object/plane.h"
#include "ray.h"
#include "vector3d.h"
#include "util.h"
#include <math.h>

static double	hit_cyl(t_object *obj, t_ray *ray);
static double	check_disk(t_object *obj, t_ray *ray, t_vector3d *p);

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	double	t = hit_cyl(obj, ray);

	t_vector3d	a = obj->data.cylinder.axis;
	vector_multiply_coeff(&a, obj->data.cylinder.height / 2);
	t_vector3d	r2;
	r2 = obj->data.cylinder.coordinates;
	vector_addition(&r2, &a);

	t_vector3d	r1;
	vector_subtract(&obj->data.cylinder.coordinates, &a, &r1);
	t = get_closest_distance(t, check_disk(obj, ray, &r1));
	t = get_closest_distance(t, check_disk(obj, ray, &r2));
	return (t);
}

static double	check_disk(t_object *obj, t_ray *ray, t_vector3d *p)
{
	t_plane	plane;
	plane.orientation = obj->data.cylinder.axis;
	plane.coordinates = *p;
	double t = solve_plane_equation(&plane, ray);
	t_vector3d bolide;
	t_vector3d bolide2;
	bolide = ray->ray;
	vector_multiply_coeff(&bolide, t);
	bolide2.x = p->x - (ray->startpos.x + bolide.x);
	bolide2.y = p->y - (ray->startpos.y + bolide.y);
	bolide2.z = p->z - (ray->startpos.z + bolide.z);
	if (powl(bolide2.x, 2) + powl(bolide2.y, 2) + powl(bolide2.z, 2) < powl(obj->data.cylinder.diameter / 2, 2))
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
	q.c = (vector_dot_product(&a0, &a0) - powl(obj->data.cylinder.diameter / 2, 2));
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
		vector_subtract(&rray, &r1, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) <= 0)
			q.r1 = -1;
		vector_subtract(&rray, &r2, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) >= 0)
			q.r1 = -1;
		rray = ray->startpos;
		rayt = ray->ray;
		vector_multiply_coeff(&rayt, q.r2);
		vector_addition(&rray, &rayt);
		vector_subtract(&rray, &r1, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) <= 0)
			q.r2 = -1;
		vector_subtract(&rray, &r2, &cmp);
		if (vector_dot_product(&cmp, &obj->data.cylinder.axis) >= 0)
			q.r2 = -1;
		return (get_closest_distance(q.r1, q.r2));
	}
	return (-1);
}
