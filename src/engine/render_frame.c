/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 06:20:52 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "shading.h"
#include "defines.h"
#include "vec4.h"

static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y);

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	t_ray	camera_ray;
	size_t	start;
	size_t	end;

	start = clock();
	i = 0;
	printf("START FRAME\n\n");
	setup_camera(engine);
	while (i < engine->scene.camera.frame_height)
	{
		j = 0;
		while (j < engine->scene.camera.frame_width)
		{
			setup_camera_ray(engine, &camera_ray, j, i);
			color_pixels(engine, i, j,
				get_pixel_color(engine, &camera_ray, DEPTH));
			++j;
		}
		++i;
	}
	end = clock();
	printf("END FRAME time: %ldms\n\n", (end - start) / 1000);
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
