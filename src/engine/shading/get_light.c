/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 06:25:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "kdtree.h"
#include "shading.h"
#include "color_util.h"
#include "photon.h"
#include <float.h>
#include <math.h>
#include "ft_math.h"

static int	trace_light(t_engine *eng, t_ray *l_ray, t_ray *c_ray, t_light *l);

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
			if (trace_light(engine, &light_ray, ray, &obj->data.light))
				phong_model(obj, &light, ray, &light_ray);
		}
		++i;
	}
	t_kaboul	kaboul;
	get_nearest_neighbour(&kaboul, engine->node, &ray->data.hitpos);
	t_ray	p_ray;
	double	d = sqrtf(kaboul.best_dist);
	p_ray.startpos = ray->startpos;
	p_ray.ray = kaboul.node->photon.pos;
	p_ray.data.color.color = kaboul.node->photon.color.color;
	if (ft_dabs(d) <= 1)
	{
		t_object obj;
		obj.data.light.pos = p_ray.startpos;
		obj.data.light.color = p_ray.data.color;
		obj.data.light.ratio = 1;
		phong_model(&obj, &light, ray, &p_ray);
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
	d = trace_ray(eng, l_ray);
	if (d < norm && d > 0 && l_ray->data.materials.refraction_ratio)
		return (0);
	return (d < 0 || d > norm);
}
