/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/04 02:53:28 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"
#include "vector3d.h"
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
		if (tmp > 0 && tmp < ray->maxlen)
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
		vector_multiply(&ray->ray, r);
		ray->hitpos = ray->startpos;
		vector_addition(&ray->hitpos, &ray->ray);
		ray->color = c;
		return (0);
	}
	return (-1);
}
