/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 23:59:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_math.h"
#include "math_util.h"
#include "object.h"
#include "quaternion.h"
#include "util.h"

static int		check_height(t_ray *ray, t_paraboloid *para);
static void		get_data(t_ray *local, t_ray *r, t_object *obj, t_hit_data *d);
static double	solve_para(t_vec3 *o, t_vec3 *d, t_ray *r, t_object *obj);
static double	check_disk(t_object *obj, t_ray *ray);

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	t_ray				local;
	double				t;
	double				t2;
	t_hit_data			data;

	local = *ray;
	vec3_subtract(&ray->startpos, &obj->data.paraboloid.pos, &local.startpos);
	quaternion_rotate(&local.startpos, &obj->data.paraboloid.rot_axis,
		obj->data.paraboloid.theta, &local.startpos);
	quaternion_rotate(&ray->ray, &obj->data.paraboloid.rot_axis,
		obj->data.paraboloid.theta, &local.ray);
	t = solve_para(&local.startpos, &local.ray, &local, obj);
	if (t != -1)
		get_data(&local, ray, obj, &data);
	t2 = check_disk(obj, ray);
	if (t2 != -1 && get_closest_distance_ptr(t2, t, &t))
		data = ray->data;
	if (t != -1)
	{
		ray->data = data;
		ray->data.color = obj->data.paraboloid.color;
		get_hitpos(ray, t);
	}
	return (t);
}

static double	solve_para(t_vec3 *start, t_vec3 *dir, t_ray *ray, t_object *o)
{
	t_quadratic	q;
	double		t;
	double		a;

	a = o->data.paraboloid.radius_coef;
	q.a = a * (dir->x * dir->x + dir->y * dir->y);
	q.b = a * 2 * (start->x * dir->x + start->y * dir->y) - dir->z;
	q.c = a * (start->x * start->x + start->y * start->y) - start->z;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	t = get_closest_distance(q.r1, q.r2);
	get_hitpos(ray, t);
	if (check_height(ray, &o->data.paraboloid))
	{
		t = get_biggest_distance(q.r1, q.r2);
		get_hitpos(ray, t);
		if (check_height(ray, &o->data.paraboloid))
			return (-1);
	}
	return (t);
}

static int	check_height(t_ray *ray, t_paraboloid *para)
{
	t_vec3			origin_hit;
	const t_vec3	axis = {0, 0, 1};
	const t_vec3	pos = {0, 0, 0};

	vec3_subtract(&ray->data.hitpos, (t_vec3 *)&pos, &origin_hit);
	if (ft_dabs(vec3_dot((t_vec3 *)&axis, &origin_hit)) > para->height)
		return (-1);
	return (0);
}

static void	get_data(t_ray *local, t_ray *ray, t_object *obj, t_hit_data *data)
{
	const double	radius_coeff = obj->data.paraboloid.radius_coef;
	double			theta;

	local->data.normal.x = 2 * radius_coeff * (local->data.hitpos.x);
	local->data.normal.y = 2 * radius_coeff * (local->data.hitpos.y);
	local->data.normal.z = -1;
	vec3_normalize(&local->data.normal);
	quaternion_rotate(&local->data.normal, &obj->data.paraboloid.rot_axis,
		-obj->data.paraboloid.theta, &ray->data.normal);
	ray->data.texture = obj->optional_data.texture;
	ray->data.normal_map = obj->optional_data.normal_map;
	theta = atan2(local->data.hitpos.y, local->data.hitpos.x);
	ray->data.u = theta / (2 * M_PI);
	if (ray->data.u < 0)
		ray->data.u += 1.0;
	ray->data.v = local->data.hitpos.z / obj->data.paraboloid.height;
	*data = ray->data;
}

static double	check_disk(t_object *obj, t_ray *ray)
{
	t_plane	plane;
	t_vec3	hitpoint;
	double	t;

	if (obj->data.paraboloid.disk == 0)
		return (-1);
	plane.pos = obj->data.paraboloid.axis;
	vec3_scale(&plane.pos, obj->data.paraboloid.height);
	vec3_add(&plane.pos, &obj->data.paraboloid.pos, &plane.pos);
	plane.normal = obj->data.paraboloid.axis;
	t = solve_plane_equation(&plane, ray);
	get_hitpos(ray, t);
	vec3_subtract(&plane.pos, &ray->data.hitpos, &hitpoint);
	if (vec3_get_norm(&hitpoint) < obj->data.paraboloid.radius)
	{
		ray->data.normal = plane.normal;
		vec3_scale(&hitpoint, 1 / (obj->data.paraboloid.radius * 2));
		quaternion_rotate(&hitpoint, &obj->data.paraboloid.rot_axis,
			obj->data.paraboloid.theta, &hitpoint);
		ray->data.u = 0.5 - hitpoint.y;
		ray->data.v = 0.5 - hitpoint.x;
		ray->data.texture = obj->optional_data.up_texture;
		ray->data.normal_map = obj->optional_data.up_normal_map;
		return (t);
	}
	return (-1);
}
