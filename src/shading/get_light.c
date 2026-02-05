/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/05 23:15:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "shading.h"
#include "vec3.h"

static int	trace_light(t_scene *scene, t_ray *l_ray, t_ray *c_ray, t_light *l);

t_colorf	get_light(t_scene *scene, t_ray *ray)
{
	t_colorf	light;
	t_light		*lights;
	t_ray		light_ray;
	size_t		i;

	i = 0;
	light = color_scale(scene->ambient_light.color, scene->ambient_light.ratio);
	lights = scene->lights.array;
	while (i < scene->lights.size)
	{
		if (trace_light(scene, &light_ray, ray, &lights[i])
			|| ray->data.obj->optional_data.has_shadow == 0)
			phong_model(lights + i, &light, ray, &light_ray);
		++i;
	}
	get_caustics(&scene->caustic, ray, &light);
	return (color_multiply(light, ray->data.color));
}

static int	trace_light(t_scene *scene, t_ray *l_ray, t_ray *c_ray, t_light *l)
{
	double	norm;
	double	d;

	l_ray->startpos = c_ray->data.hitpos;
	vec3_subtract(&l->pos, &l_ray->startpos, &l_ray->ray);
	norm = vec3_normalize(&l_ray->ray);
	get_inv_dir(l_ray);
	d = trace_ray(scene, l_ray);
	if (vec3_dot(&c_ray->data.normal, &l_ray->ray) > 0)
		return (0);
	if (d < norm && d > 0 && l_ray->data.materials->refract_index
		&& l_ray->data.obj->optional_data.photon_nb == 0)
		return (1);
	return (d < 0 || d > norm);
}
