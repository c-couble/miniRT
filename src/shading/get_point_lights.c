/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_lights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:18:26 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/09 20:18:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading.h"

static t_colorf	get_point_light(t_scene *s, t_light *light, t_ray *ray);

t_colorf	get_point_lights(t_scene *scene, t_ray *ray)
{
	size_t		i;
	t_light		*lights;
	t_colorf	lights_total;

	i = 0;
	color_zero(&lights_total);
	lights = scene->lights.array;
	while (i < scene->lights.size)
	{
		lights_total = color_add(lights_total,
				get_point_light(scene, &lights[i], ray));
		++i;
	}
	return (lights_total);
}

static t_colorf	get_point_light(t_scene *s, t_light *light, t_ray *ray)
{
	t_colorf	ret_color;
	t_ray		light_ray;
	double		dist;

	color_zero(&ret_color);
	dist = create_shadow_ray(ray, &light->pos, &light_ray);
	if (is_in_shadow(s, &light_ray, dist) == 1)
		return (ret_color);
	phong_model(light, &ret_color, ray, &light_ray);
	return (ret_color);
}
