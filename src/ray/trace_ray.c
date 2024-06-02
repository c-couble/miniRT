/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/02 02:37:00 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "vector3d.h"
#include "ray.h"
#include "object.h"
#include "math.h"
#include <stdio.h>

int	trace_ray(t_engine *engine, t_ray *ray)
{
	size_t		i;
	t_object	*obj;

	i = 0;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == SPHERE)
		{
			t_vector3d	p;
			p.x = ray->startpos.x - obj->data.sphere.coordinates.x;
			p.y = ray->startpos.y - obj->data.sphere.coordinates.y;
			p.z = ray->startpos.z - obj->data.sphere.coordinates.z;
			double a = powl(ray->ray.x, 2) + powl(ray->ray.y, 2) + powl(ray->ray.z, 2);
			double b = 2 * (p.x * ray->ray.x + p.y * ray->ray.y + p.z * ray->ray.z);
			double c = (powl(p.x, 2) + powl(p.y, 2) + powl(p.z, 2)) - powl(obj->data.sphere.diameter / 2, 2);
			double d = powl(b, 2) - (4 * a * c);
			if (d > 0)
			{
				double r1 = (-b - sqrt(d)) / (2 * a);
				double r2 = (-b + sqrt(d)) / (2 * a);
				double r;
				if (r1 <= INACCURATE_ZERO || r1 > ray->maxlen)
					r = r2;
				else if (r2 <= INACCURATE_ZERO || r2 > ray->maxlen)
					r = r1;
				else
				{
					if (r1 > r2)
						r = r2;
					else
						r = r1;
				}
				if (r <= INACCURATE_ZERO || r > ray->maxlen)
				{
					++i;
					continue;
				}
				vector_multiply(&ray->ray, r);
				ray->hitpos = ray->startpos;
				vector_addition(&ray->hitpos, &ray->ray);
				ray->color = obj->data.sphere.color;
				return (0);
			}
		}
		++i;
	}
	return (-1);
}
