/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/03 07:59:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "defines.h"
#include "object.h"
#include "ft_math.h"
#include <math.h>

int		hits_light(t_engine *engine, t_ray *l_ray, t_ray *c_ray, t_object *obj);
void	add_ambiant_light(t_color *light, t_engine *engine);
void	difuse_reflect(t_color *light, t_vec3 *light_n, t_ray *ray);
void	specular_reflect(t_color *light, t_vec3 *light_ray, t_ray *camera_ray);
void	add_phong(t_object *obj, t_color *light, t_ray *c_ray, t_ray *l_ray);

t_color	get_light(t_engine *engine, t_ray *ray)
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
		if (obj->type == LIGHT && hits_light(engine, &light_ray, ray, obj))
				add_phong(obj, &light, ray, &light_ray);
		++i;
	}
	return (light);
}

void	add_ambiant_light(t_color *light, t_engine *engine)
{
	light->color = scale_color(&engine->scene.ambient_light.color,
			engine->scene.ambient_light.ratio);
}

void	add_phong(t_object *obj, t_color *light, t_ray *c_ray, t_ray *l_ray)
{
	t_color		scene_light;

	scene_light = obj->data.light.color;
	scene_light.color = scale_color(&scene_light, obj->data.light.ratio);
	difuse_reflect(&scene_light, &l_ray->ray, c_ray);
	light->color = add_scale_color(light, &scene_light, DIFFUSE_RATIO);
	specular_reflect(&scene_light, &l_ray->ray, c_ray);
	light->color = add_scale_color(light, &scene_light, SPECULAR_RATIO);
}

// R = 2(N.L)N - L
void	specular_reflect(t_color *light, t_vec3 *light_ray, t_ray *camera_ray)
{
	double		specular_ratio;
	double		dot_nl;
	double		shine;
	t_vec3		reflection_ray;
	t_vec3		object_n;

	shine = 8;
	object_n.x = camera_ray->data.normal.x;
	object_n.y = camera_ray->data.normal.y;
	object_n.z = camera_ray->data.normal.z;
	dot_nl = vec3_dot_product(&object_n, light_ray) * 2;
	vec3_scale(&object_n, dot_nl);
	vec3_subtract(&object_n, light_ray, &reflection_ray);
	specular_ratio = vec3_dot_product(&reflection_ray, &camera_ray->ray);
	specular_ratio = ft_dabs(specular_ratio);
	specular_ratio = pow(specular_ratio, shine);
	light->color = scale_color(light, specular_ratio);
}

void	difuse_reflect(t_color *light, t_vec3 *light_n, t_ray *camera_ray)
{
	double	ratio;
	t_vec3	object_n;

	object_n.x = camera_ray->data.normal.x;
	object_n.y = camera_ray->data.normal.y;
	object_n.z = camera_ray->data.normal.z;
	ratio = vec3_dot_product(light_n, &object_n);
	ratio = ft_dabs(ratio);
	light->color = scale_color(light, ratio);
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
