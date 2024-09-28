/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 02:07:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/time.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "draw.h"
#include "color.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "shading.h"
#include "vec3.h"
#include "vec4.h"

static void	handle_single_ray(t_engine *engine, size_t i, size_t j);
static void	change_ray_size(t_engine *engine, size_t fps);
static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y);

void	*routine_t(void *arg)
{
	t_engine	*engine;

	engine = arg;
	while (1)
	{
		size_t	i;
		int	got;
		got = 0;
		while (got == 0)
		{
			pthread_mutex_lock(&engine->line_mutex);
			if (engine->current_line < engine->scene.camera.frame_height)
			{
				i = engine->current_line;
				++engine->current_line;
				got = 1;
			}
			pthread_mutex_unlock(&engine->line_mutex);
		}
		size_t	j;

		j = 0;
		while (j < engine->scene.camera.frame_width)
		{
			handle_single_ray(engine, i, j);
			++j;
		}
		pthread_mutex_lock(&engine->line_mutex);
		++engine->finished_lines;
		pthread_mutex_unlock(&engine->line_mutex);

	}
	return (NULL);
}
void	render_frame2(t_engine *engine)
{
	struct timespec	ts;
	struct timespec	ts2;

	clock_gettime(CLOCK_REALTIME, &ts);
	setup_camera(engine);
	engine->current_line = 0;
	engine->finished_lines = 0;
	pthread_mutex_unlock(&engine->line_mutex);
	pthread_mutex_lock(&engine->line_mutex);
	while (engine->finished_lines < engine->scene.camera.frame_height)
	{
		pthread_mutex_unlock(&engine->line_mutex);
		pthread_mutex_lock(&engine->line_mutex);
	}
	draw_bvh(engine);
	clock_gettime(CLOCK_REALTIME, &ts2);
	double elapsed;
	elapsed = (ts2.tv_sec - ts.tv_sec);
	elapsed += (ts2.tv_nsec - ts.tv_nsec) / 1000000000.0;
	engine->scene.camera.last_frame_time = elapsed * 1000;
	printf("frame time elapsed %lfs\n", elapsed);
	change_ray_size(engine, 1000 / engine->scene.camera.last_frame_time);
}
void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	struct timespec	ts;
	struct timespec	ts2;

	return (render_frame2(engine));
	clock_gettime(CLOCK_REALTIME, &ts);
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
	draw_bvh(engine);
	clock_gettime(CLOCK_REALTIME, &ts2);
	double elapsed;
	elapsed = (ts2.tv_sec - ts.tv_sec);
	elapsed += (ts2.tv_nsec - ts.tv_nsec) / 1000000000.0;
	engine->scene.camera.last_frame_time = elapsed * 1000;
	printf("frame time elapsed %lfs\n", elapsed);
	change_ray_size(engine, 1000 / engine->scene.camera.last_frame_time);
}

static void	handle_single_ray(t_engine *engine, size_t i, size_t j)
{
	t_ray	c_ray;
	t_color	color;

	setup_camera_ray(engine, &c_ray, j, i);
	if (engine->scene.camera.locked)
		color.color = get_pixel_color(&engine->scene, &c_ray, DEPTH);
	else
		color.color = get_pixel_color(&engine->scene, &c_ray, LOW_RENDER_DEPTH);
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
	vec4_create(&ray->ray, 0, &final);
	vec4_mat4_mult(&final, &engine->scene.camera.final, &final);
	ray->ray.x = final.x;
	ray->ray.y = final.y;
	ray->ray.z = final.z;
	vec3_normalize(&ray->ray);
	get_inv_dir(ray);
}

static void	change_ray_size(t_engine *engine, size_t fps)
{
	if (fps < MINIMUM_FPS)
		++engine->scene.camera.pixel_square_size;
	else if (fps > MAXIMUM_FPS && engine->scene.camera.pixel_square_size > 1)
		--engine->scene.camera.pixel_square_size;
}
