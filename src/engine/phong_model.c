/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:57:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 04:31:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "ft_math.h"
#include <math.h>

static void	difuse_reflect(t_color *light, t_vec3 *light_n, t_ray *ray);
static void	specular_reflect(t_color *light, t_ray *light_r, t_ray *camera_r);

void	phong_model(t_object *obj, t_color *light, t_ray *c_ray, t_ray *l_ray)
{
	t_color		scene_light;

	scene_light = obj->data.light.color;
	scene_light.color = scale_color(&scene_light, obj->data.light.ratio);
	difuse_reflect(&scene_light, &l_ray->ray, c_ray);
	light->color = add_scale_color(light, &scene_light, 
								c_ray->data.obj_material.diffuse_ratio);
	specular_reflect(&scene_light, l_ray, c_ray);
	light->color = add_scale_color(light, &scene_light, 
		c_ray->data.obj_material.specular_ratio);
}

static void	specular_reflect(t_color *light, t_ray *light_r, t_ray *camera_r)
{
	double		specular_ratio;
	double		shine;
	t_vec3		reflection_ray;

	shine = camera_r->data.obj_material.specular_shine;
	get_reflection_ray(light_r, camera_r, &reflection_ray);
	specular_ratio = vec3_dot_product(&reflection_ray, &camera_r->ray);
	specular_ratio = pow(specular_ratio, shine);
	if (specular_ratio < 0)
		return ;
	light->color = scale_color(light, specular_ratio);
}

static void	difuse_reflect(t_color *light, t_vec3 *light_n, t_ray *camera_r)
{
	double	ratio;
	t_vec3	object_n;

	object_n = camera_r->data.normal;
	ratio = vec3_dot_product(light_n, &object_n);
	ratio = ft_dabs(ratio);
	light->color = scale_color(light, ratio);
}
