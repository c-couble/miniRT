/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/01 04:56:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vec3.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"
#include "util.h"
#include <math.h>

void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid);
static int	check_height(t_ray *ray, t_paraboloid *para);

double	solve_paraboloid_equation(t_vec3 *origin, t_vec3 *dir, t_ray *ray, t_object *obj)
{
	t_quadratic	q;
	double		a;
	double		t;

	a = obj->data.paraboloid.ray_coef;
	q.a = a * (dir->x * dir->x + dir->y * dir->y);
	q.b = a * 2 * (origin->x * dir->x + origin->y * dir->y) - dir->z;
	q.c = a * (origin->x * origin->x + origin->y * origin->y) - origin->z;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	t = get_closest_distance(q.r1, q.r2);
	get_hitpos(ray, t);
	if (check_height(ray, &obj->data.paraboloid))
	{
		t = get_bigest_distance(q.r1, q.r2);
		if (t == -1)
			return (t);
		get_hitpos(ray, t);
		if (check_height(ray, &obj->data.paraboloid))
			return (-1);
	}
	return (t);
}

double	get_theta_axis(t_object *obj, t_vec3 *axis)
{
	t_vec3	z;
	t_vec3	*u;
	double	theta;

	z.x = 0;
	z.y = 0;
	z.z = -1;
	u = &obj->data.paraboloid.axis;
	vec3_cross_product(u, &z, axis);
	vec3_normalize(&z);
	theta = vec3_dot_product(u, &z) / (vec3_get_norm(u) * vec3_get_norm(&z));
	theta = acos(theta);
	//printf("theta = %lf\n", theta);
	return (theta);
}

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	t_vec3			origin;
	double			t;
	t_vec3			v;
	const double	theta = get_theta_axis(obj, &v); //same evrytimes
	t_vec3			origin2;
	t_vec3			dir2;

	vec3_subtract(&ray->startpos, &obj->data.paraboloid.pos, &origin);
	quaternion_rotate(&origin, &v, theta, &origin2);
	quaternion_rotate(&ray->ray, &v, theta, &dir2);
	t_ray	transformed_ray;
	transformed_ray.ray = dir2;
	transformed_ray.startpos = origin2;
	t = solve_paraboloid_equation(&origin2, &dir2, ray, obj);
	if (t == -1)
		return (-1);
	get_hitpos(ray, t);
	get_hitpos(&transformed_ray, t);
	get_paraboloid_normal(ray, &obj->data.paraboloid);
	//ray->data.normal = transformed_ray.data.normal;
	ray->data.color = obj->data.paraboloid.color;
	vec3_normalize(&ray->data.normal);
	return (t);
}

 void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid)
{
	ray->data.normal.x = 2 * -(paraboloid->pos.x - ray->data.hitpos.x);
	ray->data.normal.y = 2 * -(paraboloid->pos.y - ray->data.hitpos.y);
	ray->data.normal.z = -1;
}

static int	check_height(t_ray *ray, t_paraboloid *para)
{
	t_vec3		origin_hit;

	vec3_subtract(&ray->data.hitpos, &para->pos, &origin_hit);
	if (vec3_dot_product(&para->axis, &origin_hit) > para->height)
		return (-1);
	return (0);
}
