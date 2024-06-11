/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 22:34:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_util.h"
#include "object.h"
#include "object/plane.h"
#include "ray.h"
#include "vec3.h"
#include "util.h"
#include <math.h>

static double	hit_cyl(t_object *obj, t_ray *ray);
static double	check_disk(t_object *obj, t_ray *ray, t_vec3 *p);

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	double	t;
	t_vec3	a;
	t_vec3	r1;
	t_vec3	r2;

	a = obj->data.cylinder.axis;
	t = hit_cyl(obj, ray);
	vec3_scale(&a, obj->data.cylinder.height / 2);
	vec3_add(&obj->data.cylinder.coordinates, &a, &r2);
	vec3_subtract(&obj->data.cylinder.coordinates, &a, &r1);
	t = get_closest_distance(t, check_disk(obj, ray, &r1));
	t = get_closest_distance(t, check_disk(obj, ray, &r2));
	return (t);
}

static double	check_disk(t_object *obj, t_ray *ray, t_vec3 *p)
{
	t_plane	plane;
	plane.orientation = obj->data.cylinder.axis;
	plane.coordinates = *p;
	double t = solve_plane_equation(&plane, ray);
	t_vec3 bolide;
	t_vec3 bolide2;
	bolide = ray->ray;
	vec3_scale(&bolide, t);
	bolide2.x = p->x - (ray->startpos.x + bolide.x);
	bolide2.y = p->y - (ray->startpos.y + bolide.y);
	bolide2.z = p->z - (ray->startpos.z + bolide.z);
	if (powl(bolide2.x, 2) + powl(bolide2.y, 2) + powl(bolide2.z, 2) < powl(obj->data.cylinder.diameter / 2, 2))
		return (t);
	return (-1);
}

static void	solve_cylinder_quadratic(t_object *obj, t_ray *ray, t_quadratic *q)
{
	t_vec3	ra0;
	t_vec3	va;
	t_vec3	diff;

	vec3_subtract(&ray->startpos, &obj->data.cylinder.coordinates, &diff);
	vec3_cross_product(&obj->data.cylinder.axis, &diff, &ra0);
	vec3_cross_product(&ra0, &obj->data.cylinder.axis, &ra0);
	vec3_cross_product(&obj->data.cylinder.axis, &ray->ray, &va);
	vec3_cross_product(&va, &obj->data.cylinder.axis, &va);
	q->a = vec3_dot_product(&va, &va);
	q->c = (vec3_dot_product(&ra0, &ra0) - powl(obj->data.cylinder.diameter / 2, 2));
	vec3_scale(&ra0, 2);
	q->b = vec3_dot_product(&ra0, &va);
	solve_quadratic_equation(q);
}

static double	hit_cyl(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	ray->color = obj->data.cylinder.color;
	solve_cylinder_quadratic(obj, ray, &q);
	if (q.delta >= 0)
	{
		t_vec3	r1;
		t_vec3	a = obj->data.cylinder.axis;
		vec3_scale(&a, obj->data.cylinder.height / 2);
		vec3_subtract(&obj->data.cylinder.coordinates, &a, &r1);
		t_vec3	r2;
		r2 = obj->data.cylinder.coordinates;
		vec3_add(&r2, &a, &r2);
		t_vec3	rray;
		rray = ray->startpos;
		t_vec3	rayt;
		rayt = ray->ray;
		vec3_scale(&rayt, q.r1);
		vec3_add(&rray, &rayt, &rray);
		t_vec3	cmp;
		vec3_subtract(&rray, &r1, &cmp);
		if (vec3_dot_product(&cmp, &obj->data.cylinder.axis) <= 0)
			q.r1 = -1;
		vec3_subtract(&rray, &r2, &cmp);
		if (vec3_dot_product(&cmp, &obj->data.cylinder.axis) >= 0)
			q.r1 = -1;
		rray = ray->startpos;
		rayt = ray->ray;
		vec3_scale(&rayt, q.r2);
		vec3_add(&rray, &rayt, &rray);
		vec3_subtract(&rray, &r1, &cmp);
		if (vec3_dot_product(&cmp, &obj->data.cylinder.axis) <= 0)
			q.r2 = -1;
		vec3_subtract(&rray, &r2, &cmp);
		if (vec3_dot_product(&cmp, &obj->data.cylinder.axis) >= 0)
			q.r2 = -1;
		return (get_closest_distance(q.r1, q.r2));
	}
	return (-1);
}
