/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:35:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/08 19:34:54 by ccouble          ###   ########.fr       */
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

	ray->color = obj->data.sphere.color;
	vector_subtract(&ray->startpos, &obj->data.sphere.coordinates, &p);
	q.a = powl(ray->ray.x, 2) + powl(ray->ray.y, 2) + powl(ray->ray.z, 2);
	q.b = 2 * vector_dot_product(&p, &ray->ray);
	q.c = powl(p.x, 2) + powl(p.y, 2) + powl(p.z, 2) - powl(obj->data.sphere.diameter / 2, 2);
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	if ((q.r1 <= INACCURATE_ZERO || q.r1 > ray->maxlen)
		&& (q.r2 <= INACCURATE_ZERO || q.r2 > ray->maxlen))
		return (-1);
	if (q.r1 <= INACCURATE_ZERO || q.r1 > ray->maxlen)
		return (q.r2);
	if (q.r2 <= INACCURATE_ZERO || q.r2 > ray->maxlen)
		return (q.r1);
	if (q.r1 < q.r2)
		return (q.r1);
	return (q.r2);
}
