/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/16 00:06:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include "color.h"
#include "color_util.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "vec3.h"

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y);

uint32_t	get_pixel_color(t_engine *engine, int x, int y)
{
	t_ray		camera_ray;

	setup_ray(engine, &camera_ray, x, y);
	if (trace_ray(engine, &camera_ray) > 0)
	{
		camera_ray.data.color.color = get_light(engine, &camera_ray);
		if (camera_ray.data.ptr->type == SPHERE)
			get_reflect(engine, &camera_ray, &camera_ray, DEPTH);
		return (camera_ray.data.color.color);
	}
	return (BACKGROUND_COLOR);
}

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	const double	hinc = (engine->scene.camera.fov / engine->mlx.width)
		* (M_PI / 180);
	const double	vfov = (engine->scene.camera.fov * engine->mlx.height)
		/ engine->mlx.width;
	const double	vinc = (vfov / engine->mlx.height) * (M_PI / 180);
	const double	pitch = engine->scene.camera.pitch
		+ (vfov / 2) * (M_PI / 180) - vinc * y;
	const double	yaw = engine->scene.camera.yaw
		+ (engine->scene.camera.fov / 2) * (M_PI / 180) - hinc * x;

	yaw_pitch_to_vector(&ray->ray, yaw, pitch);
	ray->startpos = engine->scene.camera.coordinates;
	ray->data.color.color = BACKGROUND_COLOR;
}
