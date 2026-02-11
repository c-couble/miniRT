/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direct_lighting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:12:48 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/11 02:26:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ray.h"
#include "shading.h"

// TODO: handle nosh etc..
t_colorf	get_direct_lighting(t_scene *scene, t_ray *ray)
{
	t_colorf	direct_lighting;
	t_colorf	tmp;

	tmp = scene->ambient_light.color_times_ratio;
	direct_lighting = get_point_lights(scene, ray);
	direct_lighting = color_add(direct_lighting, tmp);
	tmp = get_area_lights(scene, ray);
	direct_lighting = color_add(direct_lighting, tmp);
	get_caustics(&scene->caustic, ray, &direct_lighting);
	return (color_multiply(direct_lighting, ray->data.color));
}
