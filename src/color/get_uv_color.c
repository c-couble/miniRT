/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:00:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:02:51 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_colorf	get_uv_color(t_ray *camera_ray)
{
	t_colorf	color;

	color.r = camera_ray->data.u;
	color.g = camera_ray->data.v;
	color.b = 0;
	return (color);
}
