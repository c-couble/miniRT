/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/15 02:13:54 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ray.h"
#include "object.h"
#include "ft_math.h"

static void	mix_lights(t_color *c1, t_color *c2, double ratio);
static int	hits_light(t_engine *engine, t_ray *ray, t_object *obj);

t_color	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	size_t		i;
	t_object	*obj;

	light.color = 0;
	i = 0;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == LIGHT)
		{
			if (hits_light(engine, ray, obj))
			{
				mix_lights(&light, &obj->data.light.color,
					obj->data.light.ratio);
				light = obj->data.light.color;
			}
		}
		mix_lights(&light, &engine->scene.ambient_light.color,
			engine->scene.ambient_light.ratio);
		++i;
	}
	return (light);
}

static void	mix_lights(t_color *c1, t_color *c2, double ratio)
{
	c1->rgb.r = ft_max(c1->rgb.r, c2->rgb.r * ratio);
	c1->rgb.g = ft_max(c1->rgb.g, c2->rgb.g * ratio);
	c1->rgb.b = ft_max(c1->rgb.b, c2->rgb.b * ratio);
}

static int	hits_light(t_engine *engine, t_ray *ray, t_object *obj)
{
	double	norm;
	double	d;

	ray->startpos = ray->data.hitpos;
	vec3_subtract(&obj->data.light.pos, &ray->startpos, &ray->ray);
	norm = vec3_normalize(&ray->ray);
	d = trace_ray(engine, ray);
	return (d < 0 || d > norm);
}
