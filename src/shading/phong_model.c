/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:57:02 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:09:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "color.h"
#include "ft_math.h"
#include "shading.h"

static void	difuse_reflect(t_colorf *light, t_vec3 *light_n, t_ray *ray);
static void	specular_reflect(t_colorf *light, t_ray *light_r, t_ray *camera_r);

void	phong_model(t_light *in, t_colorf *out, t_ray *c_ray, t_ray *l_ray)
{
	t_colorf	scene_light;

	scene_light = color_scale(in->color, in->ratio);
	difuse_reflect(&scene_light, &l_ray->ray, c_ray);
	*out = color_add_scale(*out, scene_light,
			c_ray->data.materials->diffuse_ratio);
	specular_reflect(&scene_light, l_ray, c_ray);
	*out = color_add_scale(*out,
			scene_light, c_ray->data.materials->specular_ratio);
}

static void	specular_reflect(t_colorf *light, t_ray *light_r, t_ray *camera_r)
{
	double	specular_ratio;
	t_vec3	reflection_ray;

	get_reflection_ray(light_r, camera_r, &reflection_ray);
	specular_ratio = ft_dmax(vec3_dot(&reflection_ray, &camera_r->ray), 0);
	specular_ratio = pow(specular_ratio,
			camera_r->data.materials->specular_shine);
	if (specular_ratio < 0)
		return ;
	*light = color_scale(*light, specular_ratio);
}

static void	difuse_reflect(t_colorf *light, t_vec3 *light_n, t_ray *camera_r)
{
	double	ratio;
	t_vec3	object_n;

	object_n = camera_r->data.normal;
	ratio = vec3_dot(light_n, &object_n);
	*light = color_scale(*light, -ratio);
}
