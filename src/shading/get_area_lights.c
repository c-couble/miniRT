/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_area_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:17:59 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/10 19:28:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "scene.h"
#include "shading.h"
#include "util.h"

static t_colorf	get_area_light(t_scene *s, t_area_light *a_light, t_ray *ray);
static t_vec3	sample_random_point(t_area_light *l);

t_colorf	get_area_lights(t_scene *scene, t_ray *ray)
{
	size_t			i;
	t_area_light	*area_lights;
	t_colorf		area_total;

	area_lights = scene->area_lights.array;
	color_zero(&area_total);
	i = 0;
	while (i < scene->area_lights.size)
	{
		area_total = color_add(area_total,
				get_area_light(scene, &area_lights[i], ray));
		++i;
	}
	return (area_total);
}

static t_colorf	get_area_light(t_scene *s, t_area_light *a_light, t_ray *ray)
{
	t_colorf	ret_color;
	t_light		tmp_light;
	double		dist;
	t_ray		sample_ray;

	color_zero(&ret_color);
	tmp_light.color = a_light->color;
	tmp_light.ratio = a_light->power;
	tmp_light.pos = sample_random_point(a_light);
	dist = create_shadow_ray(ray, &tmp_light.pos, &sample_ray);
	if (is_in_shadow(s, &sample_ray, dist) == 0)
	{
		phong_model(&tmp_light, &ret_color, ray, &sample_ray);
	}
	return (ret_color);
}

static t_vec3	sample_random_point(t_area_light *l)
{
	t_vec3	point;
	t_vec3	pos_u;
	t_vec3	pos_v;

	point = l->pos;
	pos_u = l->axis_u;
	pos_v = l->axis_v;
	vec3_scale(&pos_u, l->size_u * rand_range(-0.5, 0.5));
	vec3_scale(&pos_v, l->size_v * rand_range(-0.5, 0.5));
	vec3_add(&point, &pos_u, &point);
	vec3_add(&point, &pos_v, &point);
	return (point);
}
