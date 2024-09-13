/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/13 16:59:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "defines.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "texture.h"
#include "util.h"
#include "vec3.h"
#include <stdio.h>

static void	add_ray_data(t_ray *ray);

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
		if (obj->type == SPHERE)
		{
			tmp = intersect_aabb(ray, &obj->aabb);
			if (tmp != -1)
			{
				ray->data.color = obj->data.sphere.color;
				get_hitpos(ray, tmp);
				vec3_subtract(&ray->data.hitpos, &obj->data.sphere.pos,
					&ray->data.normal);
				ray->data.u = 0;
				ray->data.v = 0;
				ray->data.texture = obj->optional_data.texture;
				vec3_normalize(&ray->data.normal);
				//printf("t = %lf\n", tmp);
				ray->data.obj = obj;
				ray->data.materials = obj->optional_data.material;
				data = ray->data;
				++i ;
			}
		}
		if (obj->type == PARABOLOID)
		{
			tmp = intersect_aabb(ray, &obj->aabb);
			if (tmp != -1)
			{
				ray->data.color = obj->data.paraboloid.color;
				get_hitpos(ray, tmp);
				vec3_create(0, 1, 0, &ray->data.normal);
				ray->data.u = 0;
				ray->data.v = 0;
				ray->data.texture = obj->optional_data.texture;
				//printf("t = %lf\n", tmp);
				ray->data.obj = obj;
				ray->data.materials = obj->optional_data.material;
				data = ray->data;
				ray->data.color.color = GREEN;
				++i ;
			}
		}
		if (obj->type == CYLINDER)
		{
			tmp = intersect_aabb(ray, &obj->aabb);
			if (tmp != -1)
			{
				ray->data.color = obj->data.cylinder.color;
				get_hitpos(ray, tmp);
				vec3_create(0, 1, 0, &ray->data.normal);
				ray->data.u = 0;
				ray->data.v = 0;
				ray->data.texture = obj->optional_data.texture;
				//printf("t = %lf\n", tmp);
				ray->data.obj = obj;
				ray->data.materials = obj->optional_data.material;
				data = ray->data;
				ray->data.color.color = GREEN;
				++i ;
			}
		}
		if (get_closest_distance_ptr(tmp, t, &t))
		{
			data = ray->data;
		}
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
	apply_checkerboard(ray, ray->data.obj);
	if (ray->data.texture)
	{
		ray->data.color = get_texture_color(ray->data.texture,
				ray->data.u, ray->data.v);
	}
}
