/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/13 18:44:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "bvh.h"
#include "color.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "shading.h"
#include "vec4.h"

static void	handle_single_ray(t_engine *engine, size_t i, size_t j);
static void	change_ray_size(t_engine *engine, size_t fps);
static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y);

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	size_t	start;

	start = clock();
	i = 0;
	setup_camera(engine);
	while (i < engine->scene.camera.frame_height)
	{
		j = 0;
		while (j < engine->scene.camera.frame_width)
		{
			handle_single_ray(engine, i, j);
			++j;
		}
		++i;
	}
	draw_bounding_box(engine);
	engine->scene.camera.last_frame_time = (clock() - start) / 1000;
	change_ray_size(engine, 1000 / engine->scene.camera.last_frame_time);
}

static void	handle_single_ray(t_engine *engine, size_t i, size_t j)
{
	t_ray	camera_ray;
	t_color	color;

	setup_camera_ray(engine, &camera_ray, j, i);
	if (engine->scene.camera.locked)
		color.color = get_pixel_color(engine, &camera_ray, DEPTH);
	else
		color.color = get_pixel_color(engine, &camera_ray, 5);
	color_pixels(engine, i, j, color.color);
}

static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	double	px;
	double	py;
	t_vec4	final;

	px = (2 * ((x + 0.5) / (engine->scene.camera.frame_width)) - 1);
	py = (1 - 2 * (y + 0.5) / (engine->scene.camera.frame_height / 1.));
	ray->ray.x = px;
	ray->ray.y = -1;
	ray->ray.z = py;
	ray->startpos = engine->scene.camera.coordinates;
	vec4_create(&ray->ray, 1, &final);
	vec4_mat4_mult(&final, &engine->scene.camera.final, &final);
	ray->ray.x = final.x;
	ray->ray.y = final.y;
	ray->ray.z = final.z;
	vec3_normalize(&ray->ray);
}

static void	change_ray_size(t_engine *engine, size_t fps)
{
	if (fps < MINIMUM_FPS)
		++engine->scene.camera.pixel_square_size;
	if (fps > MAXIMUM_FPS)
		--engine->scene.camera.pixel_square_size;
}
