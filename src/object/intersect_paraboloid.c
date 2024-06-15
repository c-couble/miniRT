/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/15 02:01:47 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"
#include "util.h"

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	double		x0;
	double		y0;
	double		z0;
	double		a;

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
	return (get_closest_distance(q.r1, q.r2));
}
