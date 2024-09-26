/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/26 05:45:59 by lespenel         ###   ########.fr       */
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

static int	trace_light(t_engine *eng, t_ray *l_ray, t_ray *c_ray, t_light *l);


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
	get_caustic(engine, ray, &light);
	return (multiply_color(&light, &ray->data.color));
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
