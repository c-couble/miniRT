/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/29 05:30:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "texture.h"
#include "util.h"
#include "vec3.h"

t_color	get_texture_color(t_texture *texture, double u, double v)
{
	const int	col = u * texture->width;
	const int	line = v * texture->height;
	return (texture->texture[line * texture->width + col]);
}

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
			if (data.obj->type != SPHERE)
			{
				data.u = 0;
				data.v = 0;
			}
		}
		++i;
	}
	if (t != -1)
	{
		ray->data = data;
		ray->data.raw_normal = ray->data.normal;
		if (vec3_dot(&ray->ray, &data.normal) < 0)
			vec3_scale(&ray->data.normal, -1);
		if (ray->data.obj->optional_data.texture)
			ray->data.color = get_texture_color(ray->data.obj->optional_data.texture, ray->data.u, ray->data.v);
	}
	return (t);
}
