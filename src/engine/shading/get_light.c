/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 13:39:17 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdlib.h>
#include "color.h"
#include "object/light.h"
#include "ray.h"
#include "shading.h"
#include "vec3.h"
#include "vector.h"

static int	trace_light(t_scene *scene, t_ray *l_ray, t_ray *c_ray, t_light *l);

uint32_t	get_light(t_scene *scene, t_ray *ray)
{
	t_color		light;
	t_light		*lights;
	t_ray		light_ray;
	size_t		i;

	i = 0;
	light.color = get_ambiant_light(scene);
	lights = scene->lights.array;
	while (i < scene->lights.size)
	{
		if (trace_light(scene, &light_ray, ray, &lights[i]))
			phong_model(lights + i, &light, ray, &light_ray);
		++i;
	}
	get_caustics(&scene->caustic, ray, &light);
	return (multiply_color(&light, &ray->data.color));
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
