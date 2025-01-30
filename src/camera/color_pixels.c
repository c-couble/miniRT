/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 02:53:41 by ccouble           #+#    #+#             */
/*   Updated: 2025/01/30 15:43:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "engine.h"

void	color_pixels(t_engine *engine, int i, int j, uint32_t c)
{
	int	i2;
	int	j2;
	int	square;

	i2 = 0;
	square = engine->scene.camera.pixel_square_size;
	i *= square;
	j *= square;
	while (i2 < square && i + i2 < engine->mlx.height)
	{
		j2 = 0;
		while (j2 < square && j + j2 < engine->mlx.width)
		{
			engine->mlx.addr[((i + i2) * engine->mlx.width) + j + j2].color = c;
			++j2;
		}
		++i2;
	}
}
