/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:59:03 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/13 23:31:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "ft_math.h"
#include "vec2.h"

static void	bresenham(t_engine *eng, t_vec2 *a, t_vec2 *b);
static void	bresenham_dx(t_engine *eng, t_vec2 *a, t_vec2 *b, int *deltas);
static void	bresenham_dy(t_engine *eng, t_vec2 *a, t_vec2 *b, int *deltas);

void	draw_line(t_engine *eng, t_vec2 *a, t_vec2 *b)
{
	bresenham(eng, a, b);
	bresenham(eng, b, a);
}

static void	bresenham(t_engine *eng, t_vec2 *a, t_vec2 *b)
{
	int	dx;
	int	dy;
	int	delta_xy[2];

	if (a->x == -1 && a->y == -1)
		return ;
	if (b->x == -1 && b->y == -1)
		return ;
	if (a == NULL || b == NULL)
		return ;
	dx = ft_abs(b->x - a->x);
	dy = ft_abs(b->y - a->y);
	delta_xy[0] = dx;
	delta_xy[1] = dy;
	if (dy >= dx)
		bresenham_dy(eng, a, b, delta_xy);
	else
		bresenham_dx(eng, a, b, delta_xy);
}

static void	bresenham_dx(t_engine *eng, t_vec2 *a, t_vec2 *b, int *deltas)
{
	int	x;
	int	y;
	int	e;

	x = a->x;
	y = a->y;
	e = 2 * deltas[1] - deltas[0];
	while (x <= b->x)
	{
		if (x >= 0 && x < (int)eng->scene.camera.frame_width
			&& y >= 0 && y < (int)eng->scene.camera.frame_height)
			color_pixels(eng, y, x, GREEN);
		x++;
		if (e < 0)
			e = e + 2 * deltas[1];
		else
		{
			if (b->y - a->y < 0)
				y = y - 1;
			else
				y = y + 1;
			e = e + 2 * deltas[1] - 2 * deltas[0];
		}
	}
}

static void	bresenham_dy(t_engine *eng, t_vec2 *a, t_vec2 *b, int *deltas)
{
	int	x;
	int	y;
	int	e;

	x = a->x;
	y = a->y;
	e = 2 * deltas[0] - deltas[1];
	while (y <= b->y)
	{
		if (x >= 0 && x < (int)eng->scene.camera.frame_width
			&& y >= 0 && y < (int)eng->scene.camera.frame_height)
			color_pixels(eng, y, x, GREEN);
		y++;
		if (e < 0)
			e = e + 2 * deltas[0];
		else
		{
			if (b->x - a->x < 0)
				x = x - 1;
			else
				x = x + 1;
			e = e + 2 * deltas[0] - 2 * deltas[1];
		}
	}
}
