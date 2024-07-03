/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/03 04:43:07 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "engine.h"
#include "ray.h"
#include "vec3.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t	get_pixel_color(t_engine *engine, int x, int y);
static void		setup_ray(t_engine *engine, t_ray *ray, int x, int y);

void	print_t_color(t_color *color)
{
	printf("r = %hhu, g = %hhu, b = %hhu, uint = %u\n",
		color->rgb.r, color->rgb.g, color->rgb.b, color->color);
}


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
	const double	hinc = (engine->scene.camera.fov / engine->mlx.width)
		* (M_PI / 180);
	const double	vfov = (engine->scene.camera.fov * engine->mlx.height)
		/ engine->mlx.width;
	const double	vinc = (vfov / engine->mlx.height) * (M_PI / 180);
	const double	pitch = engine->scene.camera.pitch
		+ (vfov / 2) * (M_PI / 180) - vinc * y;
	const double	yaw = engine->scene.camera.yaw
		+ (engine->scene.camera.fov / 2) * (M_PI / 180) - hinc * x;

	yaw_pitch_to_vector(&ray->ray, yaw, pitch);
	ray->startpos = engine->scene.camera.coordinates;
}

static uint32_t	get_pixel_color(t_engine *engine, int x, int y)
{
	t_ray	camera_ray;
	t_color	color;
	t_color	light;

	setup_ray(engine, &camera_ray, x, y);
	if (trace_ray(engine, &camera_ray) > 0)
	{
		color = camera_ray.data.color;
		light = get_light(engine, &camera_ray);
		t_color c3;
		c3.color = multiply_color(&light, &color);
		print_t_color(&c3);
		return (multiply_color(&light, &color));
	}
	return (0);
}
