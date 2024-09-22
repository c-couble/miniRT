/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:07:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:43:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "draw.h"
#include "engine.h"
#include "mlx_wrapper.h"
#include "object/camera.h"
#include "vec2.h"
#include "float.h"
#include <stdio.h>
#include <stdint.h>
#include "util.h"

void	draw_graph(t_engine * eng, size_t size, double *data)
{
	const double	min = find_min(data, size);
	const double	max = find_max(data, size);
	const int		step = eng->scene.camera.frame_width / size;
	const int		height = eng->scene.camera.frame_height;
	const double	range = max - min;
	size_t			i;
	t_vec2			a;
	t_vec2			b;
	const double	height_coeff = height / range;
	printf("width = %ld\n", eng->scene.camera.frame_width);
	printf("width = %ld\n", eng->mlx.width);
	printf("step = %d height = %d, height coeft = %lf\n", step, height, height_coeff);

	i = 0;
	while (i < (size_t)size - 1)
	{
		a.x = i * step;
		a.y = height - (data[i] - min) * height_coeff;
		b.x = (i + 1) * step;
		b.y = height - (data[i + 1] - min) * height_coeff;
		draw_line(eng, &a, &b, GREEN);
		printf("a.x: %d, a.y: %d, b.x: %d, b.y: %d\n", a.x, a.y, b.x, b.y);
		draw_square(eng, 4, &a, RED);
		++i;
	}
	draw_square(eng, 4, &b, RED);
	return ;
}
