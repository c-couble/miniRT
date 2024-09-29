/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 05:55:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "normal_map.h"
#include "object.h"
#include "util.h"
#include <stdio.h>

static inline void	add_ray_data(t_ray *ray, t_hit_data *data, double t);

int	trace_ray(t_scene *scene, t_ray *ray)
{
	size_t		i;
	double		t;
	double		tmp;
	t_object	*planes;
	t_hit_data	data;

	t = intersect_bvh(ray, scene->bvh.bvh, &scene->objects);
	if (t != -1)
		data = ray->data;
	i = 0;
	planes = scene->planes.array;
	while (i < scene->planes.size)
	{
		tmp = intersect_plane(planes + i, ray);
		if (tmp > 0 && get_closest_distance_ptr(tmp, t, &t))
		{
			ray->data.obj = planes + i;
			ray->data.materials = &planes[i].optional_data.material;
			data = ray->data;
		}
		++i;
	}
	if (t != -1)
		add_ray_data(ray, &data, t);
	return (t);
}

static inline void	add_ray_data(t_ray *ray, t_hit_data *data, double t)
{
	ray->data = *data;
	ray->data.raw_normal = ray->data.normal;
	if (vec3_dot(&ray->ray, &ray->data.normal) < 0)
		vec3_scale(&ray->data.normal, -1);
	apply_checkerboard(ray, ray->data.obj);
	if (ray->data.texture)
	{
		ray->data.color = get_texture_color(ray->data.texture,
				ray->data.u, ray->data.v);
	}
	if (ray->data.normal_map)
	{
		apply_normal_map(ray);
	}
	get_hitpos(ray, t);
}
