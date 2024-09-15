/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:59:03 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/14 03:44:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "engine.h"
#include "ft_math.h"
#include "vec2.h"

static void	bresenham(t_engine *eng, t_vec2 *a, t_vec2 *b, uint32_t *color);
static void	bresenham_dx(t_engine *eng, t_line *line);
static void	bresenham_dy(t_engine *eng, t_line *line);

void	draw_line(t_engine *eng, t_vec2 *a, t_vec2 *b, uint32_t	*color)
{
	bresenham(eng, a, b, color);
	bresenham(eng, b, a, color);
}

static void	bresenham(t_engine *eng, t_vec2 *a, t_vec2 *b, uint32_t *color)
{
	t_line	line;

	if (a->x == -1 && a->y == -1)
		return ;
	if (b->x == -1 && b->y == -1)
		return ;
	if (a == NULL || b == NULL)
		return ;
	line.color = *color;
	line.a = a;
	line.b = b;
	line.dx = ft_abs(b->x - a->x);
	line.dy = ft_abs(b->y - a->y);
	if (line.dy >= line.dx)
		bresenham_dy(eng, &line);
	else
		bresenham_dx(eng, &line);
}

static void	bresenham_dx(t_engine *eng, t_line *line)
{
	int	x;
	int	y;
	int	e;

	x = line->a->x;
	y = line->a->y;
	e = 2 * line->dy - line->dx;
	while (x <= line->b->x)
	{
		if (x >= 0 && x < (int)eng->scene.camera.frame_width
			&& y >= 0 && y < (int)eng->scene.camera.frame_height)
			color_pixels(eng, y, x, line->color);
		x++;
		if (e < 0)
			e = e + 2 * line->dy;
		else
		{
			if (line->b->y - line->a->y < 0)
				y = y - 1;
			else
				y = y + 1;
			e = e + 2 * line->dy - 2 * line->dx;
		}
	}
}

static void	bresenham_dy(t_engine *eng, t_line *line)
{
	int	x;
	int	y;
	int	e;

	x = line->a->x;
	y = line->a->y;
	e = 2 * line->dx - line->dy;
	while (y <= line->b->y)
	{
		if (x >= 0 && x < (int)eng->scene.camera.frame_width
			&& y >= 0 && y < (int)eng->scene.camera.frame_height)
			color_pixels(eng, y, x, line->color);
		y++;
		if (e < 0)
			e = e + 2 * line->dx;
		else
		{
			if (line->b->x - line->a->x < 0)
				x = x - 1;
			else
				x = x + 1;
			e = e + 2 * line->dx - 2 * line->dy;
		}
	}
}
