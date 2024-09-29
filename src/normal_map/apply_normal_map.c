/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_normal_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:49:08 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 09:45:40 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "quaternion.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

void	apply_normal_map(t_ray *ray)
{
	t_vec3	axis;
	double	angle;
	t_vec3	normal;
	t_color	color;

	angle = get_theta_axis(&ray->data.normal, &axis);
	color = get_texture_color(ray->data.normal_map, ray->data.u, ray->data.v);
	normal.x = ((color.rgb.r / 255.) * 2) - 1;
	normal.y = ((color.rgb.g / 255.) * 2) - 1;
	normal.z = ((color.rgb.b / 255.) * 2) - 1;
	vec3_normalize(&normal);
	quaternion_rotate(&normal, &axis, -angle, &ray->data.normal);
	angle = get_theta_axis(&ray->data.raw_normal, &axis);
	normal.x = ((color.rgb.r / 255.) * 2) - 1;
	normal.y = ((color.rgb.g / 255.) * 2) - 1;
	normal.z = ((color.rgb.b / 255.) * 2) - 1;
	vec3_normalize(&normal);
	quaternion_rotate(&normal, &axis, -angle, &ray->data.raw_normal);
}
