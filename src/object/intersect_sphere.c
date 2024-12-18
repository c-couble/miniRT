/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:35:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 21:42:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_util.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

static void	fill_uv(t_object *obj, t_ray *ray);

double	intersect_sphere(t_object *obj, t_ray *ray)
{
	t_quadratic	q;
	t_vec3		p;
	double		t;

	vec3_subtract(&ray->startpos, &obj->data.sphere.pos, &p);
	q.a = powl(ray->ray.x, 2) + powl(ray->ray.y, 2) + powl(ray->ray.z, 2);
	q.b = 2 * vec3_dot(&p, &ray->ray);
	q.c = powl(p.x, 2) + powl(p.y, 2) + powl(p.z, 2)
		- obj->data.sphere.radiussq;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	t = get_closest_distance(q.r1, q.r2);
	if (t > 0)
	{
		ray->data.color = obj->data.sphere.color;
		get_hitpos(ray, t);
		vec3_subtract(&ray->data.hitpos, &obj->data.sphere.pos,
			&ray->data.normal);
		fill_uv(obj, ray);
		vec3_normalize(&ray->data.normal);
	}
	return (t);
}

static void	fill_uv(t_object *obj, t_ray *ray)
{
	const t_vec3	*normal = &ray->data.normal;

	ray->data.u = 0.5 + (atan2(normal->y, normal->x) / (M_PI * 2));
	ray->data.v = 0.5 - (asin(normal->z / obj->data.sphere.radius) / M_PI);
	set_texture_normal(obj, ray, 0);
}
