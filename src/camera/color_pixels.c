/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 02:53:41 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 06:18:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"
#include <stdint.h>

void	color_pixels(t_engine *engine, size_t i, size_t j, uint32_t c)
{
	size_t	i2;
	size_t	j2;
	size_t	square;

	i2 = 0;
	square = engine->scene.camera.pixel_square_size;
	while (i2 < square)
	{
		j2 = 0;
		while (j2 < square)
		{
			engine->mlx.addr[((i * square + i2) * engine->mlx.width)
				+ j * square + j2].color = c;
			++j2;
		}
		++i2;
	}
}
