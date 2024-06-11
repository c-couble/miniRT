/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:26:42 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"
#include "vec3.h"
#include "ray.h"
#include "object.h"

int	trace_ray(t_engine *engine, t_ray *ray)
{
	size_t		i;
	t_object	*obj;
	double		r;
	t_color		c;

	i = 0;
	r = -1;
	c.color = 0;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		double tmp = intersect(obj, ray);
		if (tmp > 0)
		{
			if (r == -1 || tmp < r)
			{
				r = tmp;
				c = ray->color;
			}
		}
		++i;
	}
	if (r != -1)
	{
		vec3_scale(&ray->ray, r);
		ray->hitpos = ray->startpos;
		vec3_add(&ray->hitpos, &ray->ray, &ray->hitpos);
		ray->color = c;
		return (r);
	}
	return (-1);
}
