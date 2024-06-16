/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/16 14:01:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ray.h"
#include "object.h"
#include "ft_math.h"
#include "vec3.h"
#include <stdio.h>

static void	mix_lights(t_color *c1, t_color *c2, double ratio);
static int	hits_light(t_engine *engine, t_ray *ray, t_object *obj);
static void lambertian_reflection(t_color *light, t_vec3 *object_n, t_vec3 *light_n);

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
			t_vec3 	object_n = ray->data.normal;
			if (hits_light(engine, ray, obj))
			{
				t_vec3	light_n = ray->ray;
				light = obj->data.light.color;
				lambertian_reflection(&light, &object_n, &light_n);
			}
		}
		mix_lights(&light, &engine->scene.ambient_light.color,
			engine->scene.ambient_light.ratio);
		++i;
	}
	return (light);
}

static void lambertian_reflection(t_color *light, t_vec3 *object_n, t_vec3 *light_n)
{
	double	ratio;

	ratio = vec3_dot_product(object_n, light_n);
	ft_double_abs(ratio);
	light->rgb.r *= ratio;
	light->rgb.g *= ratio;
	light->rgb.b *= ratio;
	printf("light ratio = %lf\n", ratio);
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
