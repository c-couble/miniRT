/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/23 07:33:14 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "vector.h"
#include "vec3.h"
#include "ft_math.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t	get_pixel_color(t_engine *engine, int x, int y);
static void		setup_ray(t_engine *engine, t_ray *ray, int x, int y);

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

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	double	ratio = engine->mlx.width / (double) engine->mlx.height;
	double	px = (2 * ((x + 0.5) / engine->mlx.width) - 1) * tan(engine->scene.camera.fov / 2 * M_PI / 180) * ratio;
	double	py = (1 - 2 * (y + 0.5) / engine->mlx.height) * tan(engine->scene.camera.fov / 2 * M_PI / 180);
	ray->ray.x = px;
	ray->ray.y = 1;
	ray->ray.z = py;
	vec3_normalize(&ray->ray);
	ray->startpos = engine->scene.camera.coordinates;
}

static uint32_t	get_pixel_color(t_engine *engine, int x, int y)
{
	t_ray	ray;
	t_color	color;
	t_color	light;

	setup_ray(engine, &ray, x, y);
	if (trace_ray(engine, &ray) > 0)
	{
		color = ray.data.color;
		light = get_light(engine, &ray);
		return (color.color & light.color);
	}
	return (0);
}
