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

#include "ray.h"
#include "vec3.h"

t_colorf	get_normal_color(t_ray *camera_ray)
{
	t_colorf	color;

	color.r = (camera_ray->data.normal.x + 1) * 0.5;
	color.g = (camera_ray->data.normal.y + 1) * 0.5;
	color.b = (camera_ray->data.normal.z + 1) * 0.5;
	return (color);
}
