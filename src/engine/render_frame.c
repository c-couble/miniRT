/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 04:22:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "density.h"

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
//	printf("start frame\n");
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
//	double size = 60;
//	double *datas = generate_gaussian_arr(size, 50);
//	draw_graph(engine, size, datas);
//	printf("bvh depth = %d\n", engine->scene.bvh.depth); 	
//	printf("bvh maxdepth = %d\n", engine->scene.bvh.max_depth);
	if (engine->scene.camera.render_type == BOUNDING_BOX)
		draw_bounding_boxes(engine, &engine->scene.objects, WHITE);
	draw_bvh(engine);
	long int time = clock();
	printf("end frame time %ld.%lds. \n", (time - start) / CLOCKS_PER_SEC, time -start);
	engine->scene.camera.last_frame_time = (clock() - start) / 1000;
	engine->scene.camera.last_frame_time = ((clock() - start) / 1000) + 1;
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
	vec4_create(&ray->ray, 1, &final);
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
