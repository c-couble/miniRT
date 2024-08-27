/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:35:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 06:28:02 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_util.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

double	intersect_sphere(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	t_vec3		p;
	double		t;

	vec3_subtract(&ray->startpos, &obj->data.sphere.pos, &p);
	q.a = powl(ray->ray.x, 2) + powl(ray->ray.y, 2) + powl(ray->ray.z, 2);
	q.b = 2 * vec3_dot(&p, &ray->ray);
	q.c = powl(p.x, 2) + powl(p.y, 2) + powl(p.z, 2)
		- powl(obj->data.sphere.radius, 2);
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	t = get_closest_distance(q.r1, q.r2);
	ray->data.color = obj->data.sphere.color;
	get_hitpos(ray, t);
	vec3_subtract(&ray->data.hitpos, &obj->data.sphere.pos,
		&ray->data.normal);
	vec3_normalize(&ray->data.normal);
	return (t);
}
