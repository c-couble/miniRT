/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/12 13:14:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "color_util.h"
#include "object/light.h"
#include "shading.h"
#include "vec3.h"

static int	trace_light(t_engine *eng, t_ray *l_ray, t_ray *c_ray, t_light *l);

uint32_t	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	t_light		*curr;
	t_ray		light_ray;
	size_t		i;

	i = 0;
	light.color = get_ambiant_light(engine);
	while (i < engine->scene.lights.size)
	{
		curr = at_vector(&engine->scene.lights, i);
		if (trace_light(engine, &light_ray, ray, curr))
			phong_model(curr, &light, ray, &light_ray);
		++i;
	}
	return (multiply_color(&light, &ray->data.color));
}

static int	trace_light(t_engine *eng, t_ray *l_ray, t_ray *c_ray, t_light *l)
{
	double	norm;
	double	d;

	l_ray->startpos = c_ray->data.hitpos;
	vec3_subtract(&l->pos, &l_ray->startpos, &l_ray->ray);
	norm = vec3_normalize(&l_ray->ray);
//	d = trace_ray(eng, l_ray);
	d = intersect_bvh(l_ray, eng->scene.bvh);
	if (vec3_dot(&c_ray->data.normal, &l_ray->ray) > 0)
		return (0);
	if (d < norm && d > 0 && l_ray->data.materials.refraction_ratio)
		return (1);
	return (d < 0 || d > norm);
}
