/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 17:00:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "shading.h"

uint32_t	get_pixel_color(t_engine *engine, t_ray *c_ray, int depth)
{
	t_color	color;

	if (depth <= 0)
		return (BACKGROUND_COLOR);
	if (trace_ray(engine, c_ray) > -INACCURATE_ZERO)
	{
		color.color = get_light(engine, c_ray);
		return (color.color);
	}
	return (BACKGROUND_COLOR);
}
