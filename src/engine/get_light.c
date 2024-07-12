/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/12 04:23:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "defines.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "vec3.h"

static inline int hit(double d, double norm)
{
	return (d < 0 || d > norm);
}

int	kaboul(t_engine *engine, t_ray *light_ray, t_ray *ray, t_object *obj, int depth)
{
	double	norm;
	double	d;
	t_ray	r_ray;

	if (depth <= 0)
		return (0);
	light_ray->startpos = ray->data.hitpos;
	vec3_subtract(&obj->data.light.pos, &light_ray->startpos, &light_ray->ray);
	norm = vec3_normalize(&light_ray->ray);
	d = trace_ray(engine, light_ray);
	if (ray->data.obj_t == SPHERE)
	{
		r_ray.startpos = ray->data.hitpos;
		vec3_scale(&r_ray.startpos, INACCURATE_ZERO);
		r_ray.ray = get_reflection_ray(light_ray, ray);
		double r_norm = vec3_normalize(&r_ray.ray);
		double r_d = trace_ray(engine, &r_ray);
		if (hit(r_d, r_norm))
		{
			ray->data.color = r_ray.data.color;
		}
		if (r_norm > r_d)
		{
			ray->data.color.color = BACKGROUND_COLOR;
		}
	}
	return (hit(d, norm));
}

uint32_t	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	t_object	*obj;
	t_ray		light_ray;
	size_t		i;

	i = 0;
	light.color = get_ambiant_light(engine);
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == LIGHT)
		{ 
			if (kaboul(engine, &light_ray, ray, obj, DEPTH))
			{
				phong_model(obj, &light, ray, &light_ray);
			}
		}
		++i;
	}
	return (multiply_color(&light, &ray->data.color));
}
