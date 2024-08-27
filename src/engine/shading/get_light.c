/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 07:06:54 by lespenel         ###   ########.fr       */
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

void	apply_caustic_light(t_ray *c_ray, t_kdtree *photons, t_color *pixel_light)
{
	t_kaboul	kaboul;
	t_object	obj;
	t_ray		photon_ray;
	double		norm;
	
	get_nearest_neighbour(&kaboul, photons, &c_ray->data.hitpos);
	norm = sqrtf(kaboul.best_dist);
	photon_ray.startpos = c_ray->startpos;
	photon_ray.ray = kaboul.node->photon.pos;
	photon_ray.data.color.color = kaboul.node->photon.color.color;
	if (ft_dabs(norm) <= PHOTON_DISTANCE)
	{
		obj.data.light.pos = photon_ray.startpos;
		obj.data.light.color = photon_ray.data.color;
		obj.data.light.ratio = 1;
		phong_model(&obj, pixel_light, c_ray, &photon_ray);
	}
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
			if (trace_light(engine, &light_ray, ray, &obj->data.light))
				phong_model(obj, &light, ray, &light_ray);
		}
		++i;
	}
	apply_caustic_light(ray, engine->node, &light);
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
