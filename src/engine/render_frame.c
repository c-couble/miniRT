/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 07:03:11 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/time.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "draw.h"
#include "defines.h"
#include "engine.h"

static void	change_ray_size(t_engine *engine, size_t fps);

void	render_frame(t_engine *engine)
{
	struct timespec	ts;
	struct timespec	ts2;
	double			elapsed;

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
	elapsed = (ts2.tv_sec - ts.tv_sec);
	elapsed += (ts2.tv_nsec - ts.tv_nsec) / 1000000000.0;
	engine->scene.camera.last_frame_time = elapsed * 1000 + 1;
	printf("frame time elapsed %lfs\n", elapsed);
	change_ray_size(engine, 1000 / engine->scene.camera.last_frame_time);
}

static void	change_ray_size(t_engine *engine, size_t fps)
{
	if (fps < MINIMUM_FPS)
		++engine->scene.camera.pixel_square_size;
	else if (fps > MAXIMUM_FPS && engine->scene.camera.pixel_square_size > 1)
		--engine->scene.camera.pixel_square_size;
}
