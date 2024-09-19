/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:51:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/19 09:34:09 by lespenel         ###   ########.fr       */
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
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void	draw_square(t_engine *eng, int size, t_vec2 *p, uint32_t color);


double	find_min(double *arr, size_t size)
{
	size_t	i;
	double	min;

	i = 0;
	min = DBL_MAX;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		++i;
	}
	return (min);
}

double	find_max(double *arr, size_t size)
{
	size_t	i;
	double	max;

	i = 0;
	max = -DBL_MAX;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		++i;
	}
	return (max);
}

double	gaussian_kernel(double value)
{
	double	gaussian_point;

	gaussian_point = 1 / sqrt(2 * M_PI) * exp(-(value * value) / 2);
	return (gaussian_point);
}

double	*generate_gaussian_arr(size_t size, double mu)
{
	double *datas;
	datas = malloc(sizeof(double) * size);
	if (datas == NULL)
		return (NULL);

	for (int i = 0; (size_t)i < size ; ++i)
		datas[i] = gaussian_kernel((double)(i - ((double)size / 2)) / 19);
	(void)mu;
	return (datas);
}

void	visualize_graph(t_engine * eng, int size, double *data)
{
	double min = find_min(data, size);
	double max = find_max(data, size);
	int step = eng->scene.camera.frame_width / size;
	int	height = eng->scene.camera.frame_height;
	double range = max - min;
	int	i;
	t_vec2	a;
	t_vec2	b;
	double height_coeff = height / range;
	printf("width = %ld\n", eng->scene.camera.frame_width);
	printf("width = %ld\n", eng->mlx.width);
	printf("step = %d height = %d, height coeft = %lf\n", step, height, height_coeff);

	i = 0;
	while (i < size - 1)
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
