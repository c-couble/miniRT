/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/26 06:25:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vec3.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"
#include "util.h"
#include "ft_math.h"

static int		check_height(t_ray *ray, t_paraboloid *para);
static void		get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid);
static double	solve_para(t_vec3 *o, t_vec3 *d, t_ray *r, t_object *obj);

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	const t_paraboloid	para = obj->data.paraboloid;
	t_ray				obj_ray;
	double				t;

	obj_ray = *ray;
	vec3_subtract(&ray->startpos, (t_vec3 *)&para.pos, &obj_ray.startpos);
	quaternion_rotate(&obj_ray.startpos,
		(t_vec3 *)&para.rot_axis, para.theta, &obj_ray.startpos);
	quaternion_rotate(&ray->ray, (t_vec3 *)&para.rot_axis,
		para.theta, &obj_ray.ray);
	t = solve_para(&obj_ray.startpos, &obj_ray.ray, &obj_ray, obj);
	if (t == -1)
		return (-1);
	get_paraboloid_normal(&obj_ray, &obj->data.paraboloid);
	quaternion_rotate(&obj_ray.data.normal, (t_vec3 *)
		&para.rot_axis, -para.theta, &ray->data.normal);
	get_hitpos(ray, t);
	ray->data.color = obj->data.paraboloid.color;
	return (t);
}

static double	solve_para(t_vec3 *start, t_vec3 *dir, t_ray *ray, t_object *o)
{
	t_quadratic	q;
	double		t;
	double		a;

	a = o->data.paraboloid.ray_coef;
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
	if (ft_dabs(vec3_dot_product((t_vec3 *)&axis, &origin_hit)) > para->height)
		return (-1);
	return (0);
}

static void	get_paraboloid_normal(t_ray *ray, t_paraboloid *para)
{
	ray->data.normal.x = 2 * para->ray_coef * (ray->data.hitpos.x);
	ray->data.normal.y = 2 * para->ray_coef * (ray->data.hitpos.y);
	ray->data.normal.z = -1;
	vec3_normalize(&ray->data.normal);
}
