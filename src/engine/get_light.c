/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/16 14:11:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ray.h"
#include "object.h"
#include "ft_math.h"
#include "vec3.h"

static void	mix_lights(t_color *c1, t_color *c2, double ratio);
static int	hits_light(t_engine *engine, t_ray *ray, t_object *obj);
static void	lambertian_reflect(t_color *light, t_vec3 *obj_n, t_vec3 *light_n);

t_color	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	size_t		i;
	t_object	*obj;
	t_vec3		object_n;

	light.color = 0;
	i = 0;
	object_n = ray->data.normal;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == LIGHT)
		{
			if (hits_light(engine, ray, obj))
			{
				light = obj->data.light.color;
				lambertian_reflect(&light, &object_n, &ray->ray);
			}
		}
		mix_lights(&light, &engine->scene.ambient_light.color,
			engine->scene.ambient_light.ratio);
		++i;
	}
	return (light);
}

static void	lambertian_reflect(t_color *light, t_vec3 *obj_n, t_vec3 *light_n)
{
	double	ratio;

	ratio = vec3_dot_product(light_n, obj_n);
	ratio = ft_double_abs(ratio);
	light->rgb.r *= ratio;
	light->rgb.g *= ratio;
	light->rgb.b *= ratio;
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
