/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:03:58 by ccouble           #+#    #+#             */
/*   Updated: 2025/01/30 17:37:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "shading.h"
#include "vec3.h"
#include "vec4.h"

static int	set_line(t_engine *engine, int *i);
static void	handle_single_ray(t_engine *engine, int i, int j, int t_id);
static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y);

void	*routine(void *arg)
{
	t_engine	*engine;
	int			i;
	int			j;
	int			thread_id;

	engine = arg;
	thread_id = engine->thread_run++;
	while (1)
	{
		if (set_line(engine, &i) == -1)
			return (NULL);
		j = 0;
		while (j < engine->scene.camera.frame_width)
		{
			handle_single_ray(engine, i, j, thread_id);
			++j;
		}
		pthread_mutex_lock(&engine->line_mutex);
		++engine->finished_lines;
		pthread_mutex_unlock(&engine->line_mutex);
	}
	return (NULL);
}

static int	set_line(t_engine *engine, int *i)
{
	while (1)
	{
		pthread_mutex_lock(&engine->line_mutex);
		if (engine->stop)
		{
			pthread_mutex_unlock(&engine->line_mutex);
			return (-1);
		}
		if (engine->current_line < engine->scene.camera.frame_height)
		{
			*i = engine->current_line;
			++engine->current_line;
			pthread_mutex_unlock(&engine->line_mutex);
			return (0);
		}
		pthread_mutex_unlock(&engine->line_mutex);
	}
}

static void	handle_single_ray(t_engine *engine, int i, int j, int t_id)
{
	t_ray	c_ray;
	t_color	color;

	setup_camera_ray(engine, &c_ray, j, i);
	c_ray.t_id = t_id;
	if (engine->scene.camera.locked)
		color.color = get_pixel_color(&engine->scene, &c_ray, DEPTH);
	else
		color.color = get_pixel_color(&engine->scene, &c_ray, LOW_RENDER_DEPTH);
	if (engine->scene.camera.save)
		engine->render_data[(i * engine->render_width) + j].color = color.color;
	else
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
