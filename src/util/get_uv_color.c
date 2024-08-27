/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:00:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 06:28:43 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "ray.h"

// for later
uint32_t	get_uv_color(t_ray *camera_ray)
{
	t_color	color;

	(void) camera_ray;
	color.color = 0xffffff;
	return (color.color);
}
