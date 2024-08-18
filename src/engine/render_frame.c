/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/18 16:04:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "color.h"
#include "ray.h"
#include "shading.h"
#include "defines.h"
#include "vec3.h"
#include "vec4.h"
#include "ft_math.h"
#include "photon.h"
static void	change_ray_size(t_engine *engine, size_t fps);
static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y);

double	get_closest_photon(t_engine *engine, t_ray *ray)
{
	size_t		i;
	t_photon	*curr;
	t_vec3		d;
	double		tmp;
	double		norm;
		if (ray->data.hitpos.x == 0 &&
		ray->data.hitpos.y == 0 &&
		ray->data.hitpos.z == 0)
			return (MAX_RAY_LEN);
	tmp = MAX_RAY_LEN;
	norm = MAX_RAY_LEN;
	i = 0;
	while (i < engine->photon_map.size)
	{
		curr = at_vector(&engine->photon_map, i);
		vec3_subtract(&curr->pos, &ray->data.hitpos, &d);
		tmp = vec3_get_norm(&d);
		ft_dabs(tmp);
		if (tmp < norm)
			norm = tmp;
		++i;
	}
	return (norm);
}
uint32_t	get_caustic(t_engine *engine, t_ray *ray)
{
	if (ray->data.hitpos.x == 0 &&
		ray->data.hitpos.y == 0 &&
		ray->data.hitpos.z == 0)
		return (ray->data.color.color);

	(void)engine;
	return (BACKGROUND_COLOR);
}

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	t_ray	camera_ray;
	size_t	start;

	start = clock();
	i = 0;
	printf("START FRAME\n\n");
	setup_camera(engine);
	print_photon_map(engine);
	while (i < engine->scene.camera.frame_height)
	{
		j = 0;
		while (j < engine->scene.camera.frame_width)
		{
			t_color	final_color;
			setup_camera_ray(engine, &camera_ray, j, i);
			final_color.color = get_pixel_color(engine, &camera_ray, DEPTH);
			if (get_closest_photon(engine, &camera_ray)	 < 10)
				final_color.color = SKY;
			color_pixels(engine, i, j, final_color.color);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
	change_ray_size(engine, 1000000 / (clock() - start));
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
	ray->data.hitpos.x = 0;
	ray->data.hitpos.y = 0;
	ray->data.hitpos.z = 0;
	vec3_normalize(&ray->ray);
}

static void	change_ray_size(t_engine *engine, size_t fps)
{
	if (fps < MINIMUM_FPS)
		++engine->scene.camera.pixel_square_size;
	if (fps > MAXIMUM_FPS)
		--engine->scene.camera.pixel_square_size;
}
