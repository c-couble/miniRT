/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/10 12:20:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "vector3d.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	double		dx = ray->ray.x;
	double		dy = ray->ray.y;
	double		dz = ray->ray.z;
	double		x0 = ray->startpos.x - obj->data.paraboloid.coordinates.x;
	double		y0 = ray->startpos.y - obj->data.paraboloid.coordinates.y;
	double		z0 = ray->startpos.z - obj->data.paraboloid.coordinates.z;
	double		a = obj->data.paraboloid.ray_coef;
	double		t;

	q.a = a * (dx * dx + dy * dy);
	q.b = 2 * a * (x0 * dx + y0 * dy) - dz;
	q.c = a * (x0 * x0 + y0 * y0) - z0;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	ray->color = obj->data.paraboloid.color;
	if (q.r1 > INACCURATE_ZERO && q.r2 > INACCURATE_ZERO)
	{
		if (q.r1 > q.r2)
			t = q.r2;
		else
			t = q.r1;
		return (t);
	}
	else if (q.r1 > INACCURATE_ZERO)
	{
		t = q.r1;
		return (t);
	}
	else if (q.r2 > INACCURATE_ZERO)
	{
		t = q.r2;
		return (t);
	}
	return (-1);
}
