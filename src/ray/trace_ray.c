/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/12 02:03:53 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ray.h"
#include "object.h"

int	trace_ray(t_engine *engine, t_ray *ray)
{
	size_t		i;
	t_object	*obj;
	double		r;
	t_hit_data	data;
	double		tmp;

	i = 0;
	r = -1;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		tmp = intersect(obj, ray);
		if (tmp > 0)
		{
			if (r == -1 || tmp < r)
			{
				r = tmp;
				data = ray->data;
			}
		}
		++i;
	}
	ray->data = data;
	if (r != -1)
		return (r);
	return (-1);
}
