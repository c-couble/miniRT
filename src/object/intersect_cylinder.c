/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:37:54 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_util.h"
#include "object.h"
#include "object/plane.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

static double	hit_cyl(t_object *obj, t_ray *ray, t_vec3 *r1, t_vec3 *r2);
static double	check_disk(t_object *obj, t_ray *ray, t_vec3 *p);

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	double		t;
	t_vec3		a;
	t_vec3		r1;
	t_vec3		r2;
	t_hit_data	data;

	a = obj->data.cylinder.axis;
	vec3_scale(&a, obj->data.cylinder.height / 2);
	vec3_add(&obj->data.cylinder.pos, &a, &r2);
	vec3_subtract(&obj->data.cylinder.pos, &a, &r1);
	t = hit_cyl(obj, ray, &r1, &r2);
	if (t != -1)
		data = ray->data;
	if (get_closest_distance_ptr(check_disk(obj, ray, &r1), t, &t))
		data = ray->data;
	if (get_closest_distance_ptr(check_disk(obj, ray, &r2), t, &t))
		data = ray->data;
	if (t == -1)
		return (-1);
	ray->data = data;
	ray->data.color = obj->data.cylinder.color;
	get_hitpos(ray, t);
	return (t);
}

static double	check_disk(t_object *obj, t_ray *ray, t_vec3 *p)
{
	t_plane	plane;
	t_vec3	fullray;
	t_vec3	hitpoint;
	double	t;

	plane.normal = obj->data.cylinder.axis;
	plane.pos = *p;
	t = solve_plane_equation(&plane, ray);
	fullray = ray->ray;
	vec3_scale(&fullray, t);
	vec3_subtract(p, vec3_add(&ray->startpos, &fullray, &hitpoint), &hitpoint);
	if (vec3_get_norm(&hitpoint) < obj->data.cylinder.radius)
	{
		ray->data.normal = plane.normal;
		return (t);
	}
	return (-1);
}

static void	solve_cylinder_quadratic(t_object *obj, t_ray *ray, t_quadratic *q)
{
	t_vec3	ra0;
	t_vec3	va;
	t_vec3	tmp;
	double	closest;

	vec3_subtract(&ray->startpos, &obj->data.cylinder.pos, &tmp);
	vec3_cross(&obj->data.cylinder.axis, &tmp, &ra0);
	vec3_cross(&ra0, &obj->data.cylinder.axis, &ra0);
	vec3_cross(&obj->data.cylinder.axis, &ray->ray, &va);
	vec3_cross(&va, &obj->data.cylinder.axis, &va);
	q->a = vec3_dot(&va, &va);
	q->c = vec3_dot(&ra0, &ra0) - powl(obj->data.cylinder.radius, 2);
	tmp = ra0;
	vec3_scale(&ra0, 2);
	q->b = vec3_dot(&ra0, &va);
	solve_quadratic_equation(q);
	if (q->delta < 0)
		return ;
	closest = get_closest_distance(q->r1, q->r2);
	if (closest == -1)
		return ;
	vec3_add(&tmp, vec3_scale(&va, closest), &ray->data.normal);
	vec3_normalize(&ray->data.normal);
}

static double	point_far(t_object *obj, t_vec3 *rray, t_vec3 *r1, t_vec3 *r2)
{
	t_vec3	cmp;

	vec3_subtract(rray, r1, &cmp);
	if (vec3_dot(&cmp, &obj->data.cylinder.axis) <= 0)
		return (1);
	vec3_subtract(rray, r2, &cmp);
	if (vec3_dot(&cmp, &obj->data.cylinder.axis) >= 0)
		return (1);
	return (0);
}

static double	hit_cyl(t_object *obj, t_ray *ray, t_vec3 *r1, t_vec3 *r2)
{
	t_quadratic	q;
	t_vec3		rray;
	t_vec3		rayt;

	solve_cylinder_quadratic(obj, ray, &q);
	if (q.delta >= 0)
	{
		rayt = ray->ray;
		vec3_scale(&rayt, q.r1);
		vec3_add(&ray->startpos, &rayt, &rray);
		if (point_far(obj, &rray, r1, r2))
			q.r1 = -1;
		rayt = ray->ray;
		vec3_scale(&rayt, q.r2);
		vec3_add(&ray->startpos, &rayt, &rray);
		if (point_far(obj, &rray, r1, r2))
			q.r2 = -1;
		return (get_closest_distance(q.r1, q.r2));
	}
	return (-1);
}
