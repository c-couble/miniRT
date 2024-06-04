/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:57:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/04 02:36:23 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "math_util.h"
#include "object.h"
#include "ray.h"
#include "vector3d.h"
#include <math.h>

double	intersect_cylinder(t_object *obj, t_ray *ray)
{
	t_vector3d	p;
	t_quadratic	q;

	ray->color = obj->data.cylinder.color;
	vector_subtract(&ray->startpos, &obj->data.cylinder.coordinates, &p);
	q.a = powl(ray->ray.x, 2) + powl(ray->ray.y, 2);
	q.b = 2 * (p.x * ray->ray.x + p.y * ray->ray.y);
	q.c = (powl(p.x, 2) + powl(p.y, 2)) - powl(obj->data.cylinder.diameter / 2, 2);
	solve_quadratic_equation(&q);
	if (q.delta > 0)
	{
		double r;
		if (q.r1 <= INACCURATE_ZERO || q.r1 > ray->maxlen)
			r = q.r2;
		else if (q.r2 <= INACCURATE_ZERO || q.r2 > ray->maxlen)
			r = q.r1;
		else
		{
			if (q.r1 > q.r2)
				r = q.r2;
			else
				r = q.r1;
		}
		if (r <= INACCURATE_ZERO || r > ray->maxlen)
			return (-1);
		t_vector3d rr = ray->ray;
		vector_multiply(&rr, r);
		ray->hitpos = ray->startpos;
		vector_addition(&ray->hitpos, &rr);
		double z = ray->hitpos.z - obj->data.cylinder.coordinates.z;
		if (z > obj->data.cylinder.height / 2
			|| z < obj->data.cylinder.height / -2)
			return (-1);
		ray->color = obj->data.cylinder.color;
		return (r);
	}
	return (-1);
}
