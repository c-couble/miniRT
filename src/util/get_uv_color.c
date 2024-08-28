/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:00:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 05:29:55 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "object.h"
#include "ray.h"

uint32_t	get_uv_color(t_ray *camera_ray)
{
	t_color	color;

	if (camera_ray->data.obj->type != SPHERE)
		return (0xffffff);
	double u = camera_ray->data.u;
	double v = camera_ray->data.v;
	color.rgb.r = u * 255;
	color.rgb.g = v * 255;
	color.rgb.b = 0;
	return (color.color);
}
