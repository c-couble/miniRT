/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/05 07:58:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "defines.h"
#include "math_util.h"
#include "object.h"
#include "object/plane.h"
#include "quaternion.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

static double	hit_cyl(t_object *obj, t_ray *ray, t_vec3 *r1, t_vec3 *r2);
static double	solve_cylinder_quadratic(t_object *obj, t_ray *ray);
static double	point_far(t_object *obj, t_vec3 *rray, t_vec3 *r1, t_vec3 *r2);
static double	check_disk(t_object *obj, t_ray *ray, t_vec3 *p, size_t face);

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	double		t;
	t_vec3		a;
	t_vec3		r1;
	t_vec3		r2;
	t_hit_data	data;

	a = obj->data.cylinder.axis;
	vec3_scale(&a, obj->data.cylinder.height);
	vec3_add(&obj->data.cylinder.pos, &a, &r2);
	r1 = obj->data.cylinder.pos;
	t = hit_cyl(obj, ray, &r1, &r2);
	if (t != -1)
		data = ray->data;
	if (get_closest_distance_ptr(check_disk(obj, ray, &r1, 2), t, &t))
		data = ray->data;
	if (get_closest_distance_ptr(check_disk(obj, ray, &r2, 1), t, &t))
		data = ray->data;
	if (t == -1)
		return (-1);
	ray->data = data;
	ray->data.color = obj->data.cylinder.color;
	get_hitpos(ray, t);
	return (t);
}

static double	check_disk(t_object *obj, t_ray *ray, t_vec3 *p, size_t face)
{
	t_plane	plane;
	t_vec3	hitpoint;
	double	t;

	plane.normal = obj->data.cylinder.axis;
	plane.pos = *p;
	t = solve_plane_equation(&plane, ray);
	get_hitpos(ray, t);
	vec3_subtract(p, &ray->data.hitpos, &hitpoint);
	if (vec3_get_norm(&hitpoint) < obj->data.cylinder.radius)
	{
		ray->data.normal = plane.normal;
		vec3_scale(&hitpoint, 1 / (obj->data.cylinder.radius * 2));
		quaternion_rotate(&hitpoint, &obj->data.cylinder.rot_axis,
			obj->data.cylinder.theta, &hitpoint);
		ray->data.u = 0.5 - hitpoint.y;
		ray->data.v = 0.5 - hitpoint.x;
		if (face == 1)
			ray->data.texture = obj->optional_data.up_texture;
		else
			ray->data.texture = obj->optional_data.down_texture;
		return (t);
	}
	return (-1);
}

static double	hit_cyl(t_object *obj, t_ray *ray, t_vec3 *r1, t_vec3 *r2)
{
	const double	t = solve_cylinder_quadratic(obj, ray);
	t_vec3			local;

	if (t == -1)
		return (-1);
	get_hitpos(ray, t);
	if (point_far(obj, &ray->data.hitpos, r1, r2))
		return (-1);
	vec3_subtract(&ray->data.hitpos, &obj->data.cylinder.pos, &local);
	quaternion_rotate(&local, &obj->data.cylinder.rot_axis,
		obj->data.cylinder.theta, &local);
	ray->data.u = 0.5 + (atan2(local.y, local.x)) / (M_PI * 2);
	ray->data.v = 1 - (local.z / obj->data.cylinder.height);
	ray->data.texture = obj->optional_data.texture;
	return (t);
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

static double	solve_cylinder_quadratic(t_object *obj, t_ray *ray)
{
	t_vec3		ra0;
	t_vec3		va;
	t_vec3		tmp;
	t_quadratic	q;
	double		closest;

	vec3_subtract(&ray->startpos, &obj->data.cylinder.pos, &tmp);
	vec3_cross(&obj->data.cylinder.axis, &tmp, &ra0);
	vec3_cross(&ra0, &obj->data.cylinder.axis, &ra0);
	vec3_cross(&obj->data.cylinder.axis, &ray->ray, &va);
	vec3_cross(&va, &obj->data.cylinder.axis, &va);
	q.a = vec3_dot(&va, &va);
	q.c = vec3_dot(&ra0, &ra0) - powl(obj->data.cylinder.radius, 2);
	tmp = ra0;
	vec3_scale(&ra0, 2);
	q.b = vec3_dot(&ra0, &va);
	solve_quadratic_equation(&q);
	if (q.delta < INACCURATE_ZERO)
		return (-1);
	closest = get_closest_distance(q.r1, q.r2);
	if (closest == -1)
		return (-1);
	vec3_add(&tmp, vec3_scale(&va, closest), &ray->data.normal);
	vec3_normalize(&ray->data.normal);
	return (closest);
}
