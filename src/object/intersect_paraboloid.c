/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/27 19:18:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "vec3.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"
#include "util.h"
#include "ft_math.h"

static void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid);

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	double		x0;
	double		y0;
	double		z0;
	double		a;
	double		t;

	x0 = ray->startpos.x - obj->data.paraboloid.pos.x;
	y0 = ray->startpos.y - obj->data.paraboloid.pos.y;
	z0 = ray->startpos.z - obj->data.paraboloid.pos.z;
	a = obj->data.paraboloid.ray_coef;
	q.a = a * (ray->ray.x * ray->ray.x + ray->ray.y * ray->ray.y);
	q.b = 2 * a * (x0 * ray->ray.x + y0 * ray->ray.y) - ray->ray.z;
	q.c = a * (x0 * x0 + y0 * y0) - z0;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	ray->data.color = obj->data.paraboloid.color;
	t = get_closest_distance(q.r1, q.r2);
	get_hitpos(ray, t);
	if (ft_dabs(ray->data.hitpos.z -obj->data.paraboloid.pos.z) 
		> obj->data.paraboloid.height)
		return (-1);
	get_paraboloid_normal(ray, &obj->data.paraboloid);
	return (t);
}

static void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid)
{
	ray->data.normal.x = -2 * (ray->data.hitpos.x - paraboloid->pos.x);
	ray->data.normal.y = -2 * (ray->data.hitpos.y - paraboloid->pos.y);
	ray->data.normal.z = 1;
	vec3_normalize(&ray->data.normal);
}
