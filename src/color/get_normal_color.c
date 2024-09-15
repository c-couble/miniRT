/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 18:01:10 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ray.h"

uint32_t	get_normal_color(t_ray *camera_ray)
{
	t_color	color;

	color.rgb.r = (camera_ray->data.normal.x + 1) * 0.5 * 255;
	color.rgb.g = (camera_ray->data.normal.y + 1) * 0.5 * 255;
	color.rgb.b = (camera_ray->data.normal.z + 1) * 0.5 * 255;
	return (color.color);
}
