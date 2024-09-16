/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:15:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 20:19:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "engine.h"
#include "object.h"
#include "util.h"

static void	add_ray_data(t_ray *ray);

int	trace_ray2(t_engine *engine, t_ray *ray)
{
	size_t		i;
	double		t;
	double		tmp;
	t_object	*obj;
	t_hit_data	data;

	i = 0;
	t = intersect_bvh(ray, engine->scene.bvh, &engine->scene.objects);
	if (t != -1)
		data = ray->data;
	while (i < engine->scene.planes.size)
	{
		obj = at_vector(&engine->scene.planes, i);
		tmp = intersect(obj, ray);
		if (get_closest_distance_ptr(tmp, t, &t))
			data = ray->data;
		++i;
	}
	if (t != -1)
	{
		ray->data = data;
		add_ray_data(ray);
	}
	return (t);
}

static void	add_ray_data(t_ray *ray)
{
	ray->data.raw_normal = ray->data.normal;
	if (vec3_dot(&ray->ray, &ray->data.normal) < 0)
		vec3_scale(&ray->data.normal, -1);
//	apply_checkerboard(ray, ray->data.obj);
//	if (ray->data.texture)
//	{
//		ray->data.color = get_texture_color(ray->data.texture,
//				ray->data.u, ray->data.v);
//	}
}
