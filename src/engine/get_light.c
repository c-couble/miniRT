/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/02 09:23:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "object.h"
#include "ft_math.h"
#include "vec3.h"
#include <math.h>
#include <stdio.h>

void	mix_lights(t_color *c1, t_color *c2, double ratio);
int	hits_light(t_engine *engine, t_ray *light_ray, t_ray *ray, t_object *obj);
void	difuse_reflect(t_color *light, t_vec3 *obj_n, t_vec3 *light_n);
void	specular_reflect(t_color *light, t_vec3 *obj_n, t_vec3 *light_n, t_ray *ray);

t_color	get_light(t_engine *engine, t_ray *ray)
{
	t_color		light;
	t_object	*obj;
	t_ray		light_ray;
	t_color		scene_light;
	t_vec3		object_n;
	size_t		i;

	light.color = 0;
	i = 0;
	mix_lights(&light, &engine->scene.ambient_light.color,
			engine->scene.ambient_light.ratio);
	object_n = ray->data.normal;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == LIGHT)
		{
			if (hits_light(engine, &light_ray, ray, obj))
			{
				scene_light = obj->data.light.color;
				scene_light.rgb.r *= obj->data.light.ratio;
				scene_light.rgb.g *= obj->data.light.ratio;
				scene_light.rgb.b *= obj->data.light.ratio;
				difuse_reflect(&scene_light, &object_n, &light_ray.ray);
				mix_lights(&light, &scene_light, DIFFUSE_RATIO * obj->data.light.ratio);
				specular_reflect(&scene_light, &object_n, &light_ray.ray, ray);
				mix_lights(&light, &scene_light, SPECULAR_RATIO * obj->data.light.ratio);
			}
		}
				++i;
	}
	return (light);
}

// R = 2(N.L)N - L
//

void	specular_reflect(t_color *light, t_vec3 *obj_n, t_vec3 *light_ray, t_ray *ray)
{
	double	specular_ratio;
	t_vec3	reflection_ray;
	double	dot_N_L;
	double	shine = 8;


	t_vec3 *temp_N = vec3_scale(obj_n, 1);
	dot_N_L = vec3_dot_product(temp_N, light_ray) * 2;
	vec3_scale(temp_N, dot_N_L);
	vec3_subtract(temp_N, light_ray, &reflection_ray);
	
	specular_ratio = vec3_dot_product(&reflection_ray, &ray->ray);
	if (specular_ratio > 0)
		specular_ratio = 0;
	specular_ratio = ft_dabs(specular_ratio);
	specular_ratio = pow(specular_ratio, shine);

	light->rgb.r *= specular_ratio;
	light->rgb.g *= specular_ratio;
	light->rgb.b *= specular_ratio;
}

void	difuse_reflect(t_color *light, t_vec3 *obj_n, t_vec3 *light_n)
{
	double	ratio;

	ratio = vec3_dot_product(light_n, obj_n);
	ratio = ft_dabs(ratio);
	light->rgb.r *= ratio;
	light->rgb.g *= ratio;
	light->rgb.b *= ratio;
}

void	mix_lights(t_color *c1, t_color *c2, double ratio)
{
	c1->rgb.r = ft_dmin(255, c1->rgb.r + c2->rgb.r * ratio);
	c1->rgb.g = ft_dmin(255, c1->rgb.g + c2->rgb.g * ratio);
	c1->rgb.b = ft_dmin(255, c1->rgb.b + c2->rgb.b * ratio);
}

int	hits_light(t_engine *engine, t_ray *light_ray, t_ray *ray, t_object *obj)
{
	double	norm;
	double	d;

	light_ray->startpos = ray->data.hitpos;
	vec3_subtract(&obj->data.light.pos, &light_ray->startpos, &light_ray->ray);
	norm = vec3_normalize(&light_ray->ray);
	d = trace_ray(engine, light_ray);
	return (d < 0 || d > norm);
}
