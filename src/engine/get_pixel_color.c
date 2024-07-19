/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:11:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/19 11:39:41 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "color_util.h"
#include "defines.h"
#include "engine.h"
#include "ray.h"
#include "vec3.h"
#include "vec4.h"

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y);

uint32_t	get_pixel_color(t_engine *engine, int x, int y)
{
	t_ray	camera_ray;
	t_vec4	final;

	setup_ray(engine, &camera_ray, x, y);
	vec4_create(&camera_ray.ray, 1, &final);
	vec4_mat4_mult(&final, &engine->scene.camera.final, &final);
	camera_ray.ray.x = final.x;
	camera_ray.ray.y = final.y;
	camera_ray.ray.z = final.z;
	vec3_normalize(&camera_ray.ray);
	if (trace_ray(engine, &camera_ray) > 0)
	{
		//camera_ray.data.color.color = get_normal_color(&camera_ray);
		camera_ray.data.color.color = get_light(engine, &camera_ray);
		if (camera_ray.data.ptr->type == SPHERE)
		{
			get_refract(engine, &camera_ray,&camera_ray,DEPTH,AIR_RATIO,GLASS_RATIO);
		//	get_reflect(engine, &camera_ray, &camera_ray, DEPTH);
		}
		return (camera_ray.data.color.color);
	}
	return (BACKGROUND_COLOR);

}

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	const double	px = (2 * ((x + 0.5) / engine->mlx.width) - 1);
	const double	py = (1 - 2 * (y + 0.5) / engine->mlx.height);

	ray->ray.x = px;
	ray->ray.y = -1;
	ray->ray.z = py;
	ray->startpos = engine->scene.camera.coordinates;
}
