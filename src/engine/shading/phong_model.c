/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:57:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 17:05:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "ft_math.h"
#include "shading.h"

static void	diffuse_reflect(t_color *light, t_vec3 *light_n, t_ray *ray);

void	phong_model(t_object *obj, t_color *light, t_ray *c_ray, t_ray *l_ray)
{
	t_color		scene_light;

	scene_light = obj->data.light.color;
	scene_light.color = scale_color(&scene_light, obj->data.light.ratio);
	diffuse_reflect(&scene_light, &l_ray->ray, c_ray);
	light->color = add_scale_color(light, &scene_light, 1);
}

static void	diffuse_reflect(t_color *light, t_vec3 *light_n, t_ray *camera_r)
{
	double	ratio;
	t_vec3	object_n;

	object_n = camera_r->data.normal;
	ratio = vec3_dot(light_n, &object_n);
	ratio = ft_dabs(ratio);
	light->color = scale_color(light, ratio);
}
