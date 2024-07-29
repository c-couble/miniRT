/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 02:53:41 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 02:56:38 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"

void	color_pixels(t_engine *engine, size_t i, size_t j, t_color c)
{
	size_t	i2 = 0;
	while (i2 < engine->scene.camera.pixel_square_size)
	{
		size_t	j2 = 0;
		while (j2 < engine->scene.camera.pixel_square_size)
		{
			engine->mlx.addr[((i * engine->scene.camera.pixel_square_size + i2) * engine->mlx.width) + j * engine->scene.camera.pixel_square_size + j2] = c;
			++j2;
		}
		++i2;
	}
}
