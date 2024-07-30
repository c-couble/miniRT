/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/31 01:56:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vec3.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"
#include "util.h"
#include <math.h>

 void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid, int i);
static int	check_height(t_ray *ray, t_vec3 *axis, t_paraboloid *para);
double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	t_vec3		origin;
	t_quadratic	q;
	double		a;
	double		t;

	t_vec3	u = obj->data.paraboloid.axis;
	vec3_normalize(&u);
	t_vec3	v;
	t_vec3  z = {0,0,1};
	vec3_cross_product(&u, &z, &v);
	vec3_normalize(&z);
	double	theta = vec3_dot_product(&u, &z) / (vec3_get_norm(&u) * vec3_get_norm(&z));
	theta = acos(theta);
	//same evrytimes
	t_vec3	origin2;
	t_vec3	dir2;

	vec3_subtract(&ray->startpos, &obj->data.paraboloid.pos, &origin);
	quaternion_rotate(&origin, &v, theta, &origin2);
	quaternion_rotate(&ray->ray, &v, theta, &dir2);
	//printf("theta = %lf\n", theta);
	a = obj->data.paraboloid.ray_coef;
	q.a = a * (dir2.x * dir2.x + dir2.y * dir2.y);
	q.b = a * 2 * (origin2.x * dir2.x + origin2.y * dir2.y) - dir2.z;
	q.c = a * (origin2.x * origin2.x + origin2.y * origin2.y) - origin2.z;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	t = get_closest_distance(q.r1, q.r2);
	get_hitpos(ray, t);
	t_ray lol;
	lol.ray = dir2;
	lol.startpos = origin2;
	get_hitpos(&lol, t);
	if (check_height(ray, &obj->data.paraboloid.axis, &obj->data.paraboloid))
	{
		t = get_bigest_distance(q.r1, q.r2);
		if (t == -1)
			return (t);
		get_hitpos(ray, t);
		if (check_height(ray, &obj->data.paraboloid.axis, &obj->data.paraboloid))
			return (-1);
		get_paraboloid_normal(ray, &obj->data.paraboloid, -1);
	}
	else
		get_paraboloid_normal(ray, &obj->data.paraboloid, -1);
	ray->data.color = obj->data.paraboloid.color;
	return (t);
}

 void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid, int i)
{
	ray->data.normal.x = 2 * (ray->data.hitpos.x - paraboloid->pos.x);
	ray->data.normal.y = 2 * (ray->data.hitpos.y - paraboloid->pos.y);
	ray->data.normal.z = i;
	vec3_normalize(&ray->data.normal);
}

static int	check_height(t_ray *ray, t_vec3 *axis, t_paraboloid *para)
{
	t_vec3		ot;

	vec3_subtract(&ray->data.hitpos, &para->pos, &ot);
	if (vec3_dot_product(axis, &ot) > para->height)
		return (-1);
	return (0);
}
