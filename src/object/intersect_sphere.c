/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:35:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/04 02:33:13 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "math_util.h"
#include "object.h"
#include "ray.h"
#include "vector3d.h"
#include <math.h>

double	intersect_sphere(t_object *obj, t_ray *ray)
{
	t_vector3d	p;
	t_quadratic	q;
	double r;

	ray->color = obj->data.sphere.color;
	vector_subtract(&ray->startpos, &obj->data.sphere.coordinates, &p);
	q.a = vector_get_norm(&ray->ray);
	q.b = 2 * vector_dot_product(&p, &ray->ray);
	q.c = (vector_get_norm(&p)) - powl(obj->data.sphere.diameter / 2, 2);
	solve_quadratic_equation(&q);
	if (q.delta > 0)
	{
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
		return (r);
	}
	return (-1);
}
