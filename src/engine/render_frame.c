/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/* j Updated: 2024/05/30 04:52:43 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object.h"
#include "ray.h"
#include "vector.h"
#include "vector3d.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	double	hinc = (engine->scene.camera.fov / engine->mlx.width) * (M_PI / 180);
	double	vfov = (engine->scene.camera.fov * engine->mlx.height) / engine->mlx.width;
	double	vinc = (vfov / engine->mlx.height) * (M_PI / 180);

	i = 0;
	printf("START FRAME %lf\n\n", vfov);
	while (i < engine->mlx.height)
	{
		double pitch = engine->scene.camera.pitch
				+ (vfov / 2) * (M_PI / 180)
				- vinc * i;
		j = 0;
		while (j < engine->mlx.width)
		{
			double yaw = engine->scene.camera.yaw
				+ (engine->scene.camera.fov / 2) * (M_PI / 180)
				- hinc * j;
			t_ray	ray;
			yaw_pitch_to_vector(&ray.ray, yaw, pitch);
			
		 	if (trace_ray(engine, &ray) == 0)
				engine->mlx.addr[(i * engine->mlx.width) + j].color = ray.color.color;
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}
