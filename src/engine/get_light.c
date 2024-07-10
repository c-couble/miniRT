/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/10 05:10:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "defines.h"
#include "object.h"
#include "ray.h"

int		trace_light(t_engine *engine, t_ray *l_ray, t_ray *c_ray, t_object *obj);
static void	add_ambiant_light(t_color *light, t_engine *engine);

int	trace_light(t_engine *engine, t_ray *light_ray, t_ray *ray, t_object *obj)
{
	double	norm;
	double	d;

	light_ray->startpos = ray->data.hitpos;
	vec3_subtract(&obj->data.light.pos, &light_ray->startpos, &light_ray->ray);
	norm = vec3_normalize(&light_ray->ray);
	d = trace_ray(engine, light_ray);
	return (d < 0 || d > norm);
}

int	kaboul(t_engine *engine, t_ray *light_ray, t_ray *ray, t_object *obj, int depth)
{
	double	norm;
	double	d;

	light_ray->startpos = ray->data.hitpos;
	vec3_subtract(&obj->data.light.pos, &light_ray->startpos, &light_ray->ray);
	norm = vec3_normalize(&light_ray->ray);
	d = trace_ray(engine, light_ray);
	(void)depth;
	return (d < 0 || d > norm);
}

uint32_t	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	t_object	*obj;
	t_ray		light_ray;
	size_t		i;

	i = 0;
	add_ambiant_light(&light, engine);
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == LIGHT && kaboul(engine, &light_ray, ray, obj, DEPTH))
				phong_model(obj, &light, ray, &light_ray);
		++i;
	}
	return (multiply_color(&light, &ray->data.color));
}

static void	add_ambiant_light(t_color *light, t_engine *engine)
{
	light->color = scale_color(&engine->scene.ambient_light.color,
			engine->scene.ambient_light.ratio);
}
