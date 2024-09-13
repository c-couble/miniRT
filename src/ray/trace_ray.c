/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/13 04:52:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object.h"
#include "ray.h"
#include "texture.h"
#include "util.h"
#include "vec3.h"

static void	add_ray_data(t_ray *ray, double t);

int	trace_ray(t_engine *engine, t_ray *ray)
{
	size_t		i;
	t_object	*obj;
	double		t;
	t_hit_data	data;
	double		tmp;

	i = 0;
	t = -1;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		tmp = intersect(obj, ray);
		if (get_closest_distance_ptr(tmp, t, &t))
		{
			data = ray->data;
		}
		++i;
	}
	if (t != -1)
	{
		ray->data = data;
		add_ray_data(ray, t);
	}
	return (t);
}

static void	add_ray_data(t_ray *ray, double t)
{
	ray->data.raw_normal = ray->data.normal;
	if (vec3_dot(&ray->ray, &ray->data.normal) < 0)
		vec3_scale(&ray->data.normal, -1);
	if (ray->data.texture)
	{
		ray->data.color = get_texture_color(ray->data.texture,
				ray->data.u, ray->data.v);
	}
	get_hitpos(ray, t);
}
