/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/22 07:27:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "object/camera.h"
#include <stdio.h>
#include "engine.h"
#include "ray.h"
#include "vec3.h"
#include "vec4.h"

static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y);

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	t_ray	camera_ray;

	i = 0;
	printf("START FRAME\n\n");
	setup_camera(engine);
	while (i < engine->mlx.height)
	{
		j = 0;
		while (j < engine->mlx.width)
		{
			setup_camera_ray(engine, &camera_ray, j, i);
			engine->mlx.addr[(i * engine->mlx.width) + j].color
				= get_pixel_color(engine, &camera_ray, DEPTH);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}

static void	setup_camera_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	const double	px = (2 * ((x + 0.5) / engine->mlx.width) - 1);
	const double	py = (1 - 2 * (y + 0.5) / engine->mlx.height);
	t_vec4			final;

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
