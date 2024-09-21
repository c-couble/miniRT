/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:14:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:15:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "vec2.h"

void	draw_square(t_engine *eng, int size, t_vec2 *p, uint32_t color)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			color_pixels(eng, p->y - i, p->x - j, color);
			color_pixels(eng, p->y + i, p->x + j, color);
			color_pixels(eng, p->y - i, p->x + j, color);
			color_pixels(eng, p->y + i, p->x - j, color);
			++j;
		}
		++i;
	}
}
