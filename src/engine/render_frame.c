/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/12 06:14:08 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include "engine.h"

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("START FRAME\n\n");
	while (i < engine->mlx.height)
	{
		j = 0;
		while (j < engine->mlx.width)
		{
			engine->mlx.addr[(i * engine->mlx.width) + j].color
				= get_pixel_color(engine, j, i);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}
