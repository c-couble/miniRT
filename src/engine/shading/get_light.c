/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/19 01:25:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "defines.h"
#include "kdtree.h"
#include "photon.h"
#include "color.h"
#include "object/light.h"
#include "ray.h"
#include "shading.h"
#include "vec3.h"
#include "vector.h"
#include "object.h"

static int	trace_light(t_engine *eng, t_ray *l_ray, t_ray *c_ray, t_light *l);
static void	apply_caustic_light(t_ray *ray, t_kdtree *photons, t_color *light);

uint32_t	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	t_light		*lights;
	t_ray		light_ray;
	size_t		i;

	i = 0;
	light.color = get_ambiant_light(engine);
	lights = engine->scene.lights.array;
	while (i < engine->scene.lights.size)
	{
		if (trace_light(engine, &light_ray, ray, &lights[i]))
			phong_model(&lights[i], &light, ray, &light_ray);
		++i;
	}
	if (ray->data.materials.refract_index == 0)
	{
		size_t		j;
		t_kdtree	**node;

		j = 0;
		while (j < engine->caustic_maps.size)
		{
			node = at_vector(&engine->caustic_maps, j);
			apply_caustic_light(ray, *node, &light);
			++j;
		}
	}
	return (multiply_color(&light, &ray->data.color));
}

int init_knn(t_knn *knn, size_t k)
{
	size_t	i;

	knn->querys = malloc(sizeof(t_query) * k);
	if (knn->querys == NULL)
		return (-1);
	knn->count = 0;
	knn->size = k;
	knn->farest = 0;
	i = 0;
	while (i < k)
	{
		knn->querys[i].node = NULL;
		knn->querys[i].dist = DBL_MAX;
		++i;
	}
	return (0);
}

static void	apply_caustic_light(t_ray *c_ray, t_kdtree *photons, t_color *light)
{
	t_object	obj;
	t_ray		photon_ray;
	double		norm;
	t_knn		knn;

	if (init_knn(&knn, 5) == -1)
		return ;
	get_nearest_neighbour2(&knn, photons, &c_ray->data.hitpos);
	print_knn(&knn);
	for (size_t i = 0; i < knn.count; ++i)
	{
		norm = sqrtf(knn.querys[i].dist);
		photon_ray.startpos = c_ray->startpos;
		photon_ray.ray = knn.querys[i].node->photon.pos;
		photon_ray.data.color.color = knn.querys[i].node->photon.color.color;
		if (norm < PHOTON_RADIUS)
		{
			obj.data.light.pos = photon_ray.startpos;
			obj.data.light.color = photon_ray.data.color;
			obj.data.light.ratio = knn.querys[i].node->photon.ratio;
			phong_model(&obj.data.light, light, c_ray, &photon_ray);
		}
	}
}

static int	trace_light(t_engine *eng, t_ray *l_ray, t_ray *c_ray, t_light *l)
{
	double	norm;
	double	d;

	l_ray->startpos = c_ray->data.hitpos;
	vec3_subtract(&l->pos, &l_ray->startpos, &l_ray->ray);
	norm = vec3_normalize(&l_ray->ray);
	get_inv_dir(l_ray);
	d = trace_ray(eng, l_ray);
	if (vec3_dot(&c_ray->data.normal, &l_ray->ray) > 0)
		return (0);
	if (d < norm && d > 0 && l_ray->data.materials.refract_index)
		return (0);
	return (d < 0 || d > norm);
}
