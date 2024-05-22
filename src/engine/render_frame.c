/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/22 04:56:13 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <math.h>

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < engine->mlx.height)
	{
		j = 0;
		while (j < engine->mlx.width)
		{
			if (sqrt(powl((long)j - 1000, 2) + powl((long)i - 500, 2)) < 100)
				engine->mlx.addr[(i * engine->mlx.width) + j].color = 0xff0000;
			++j;
		}
		++i;
	}
}
