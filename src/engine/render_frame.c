/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/16 20:25:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "mat4.h"
#include "object/camera.h"
#include "ray.h"
#include "vec4.h"
#include "vec3.h"
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
	setup_camera(&engine->scene.camera);
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
	double	px = (2 * ((x + 0.5) / engine->mlx.width) - 1);
	double	py = (1 - 2 * (y + 0.5) / engine->mlx.height);
	//double	ratio = engine->mlx.width / (double) engine->mlx.height;
	//px *= tan(engine->scene.camera.fov / 2 * M_PI / 180) * ratio;
	//py *= tan(engine->scene.camera.fov / 2 * M_PI / 180);
	ray->ray.x = px;
	ray->ray.y = -1;
	ray->ray.z = py;
	ray->startpos = engine->scene.camera.coordinates;
}

static uint32_t	get_pixel_color(t_engine *engine, int x, int y)
{
	t_ray	ray;
	t_color	color;
	t_color	light;

	setup_ray(engine, &ray, x, y);
	t_vec4	final;
	vec4_create(&ray.ray, 1, &final);
	vec4_mat4_mult(&final, &engine->scene.camera.final, &final);
	ray.ray.x = final.x;
	ray.ray.y = final.y;
	ray.ray.z = final.z;
	vec3_normalize(&ray.ray);
	if (trace_ray(engine, &ray) > 0)
	{
		color = ray.data.color;
		light = get_light(engine, &ray);
		return (color.color & light.color);
	}
	return (0);
}
