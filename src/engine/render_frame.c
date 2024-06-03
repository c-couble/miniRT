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

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "object.h"
#include "ray.h"
#include "vector.h"
#include "vector3d.h"
#include "ft_math.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t	get_pixel_color(t_engine *engine, int x, int y);

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("START FRAME\n\n");
	while (i < engine->mlx.height)
	{
		j = 0;
		while (j < engine->mlx.width)
		{
			engine->mlx.addr[(i * engine->mlx.width) + j].color = get_pixel_color(engine, j, i);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}

static uint32_t	get_pixel_color(t_engine *engine, int x, int y)
{
	double	hinc = (engine->scene.camera.fov / engine->mlx.width) * (M_PI / 180);
	double	vfov = (engine->scene.camera.fov * engine->mlx.height) / engine->mlx.width;
	double	vinc = (vfov / engine->mlx.height) * (M_PI / 180);
	double pitch = engine->scene.camera.pitch
		+ (vfov / 2) * (M_PI / 180)
	- vinc * y;
	double yaw = engine->scene.camera.yaw
				+ (engine->scene.camera.fov / 2) * (M_PI / 180)
				- hinc * x;
	t_ray	ray;

	yaw_pitch_to_vector(&ray.ray, yaw, pitch);
	ray.startpos = engine->scene.camera.coordinates;
	ray.maxlen = MAX_RAY_LEN;
	if (trace_ray(engine, &ray) == 0)
	{
		t_color	color;
		color = ray.color;
		t_color	light;
		light.color = 0;
		size_t	i = 0;
		while (i < engine->scene.objects.size)
		{
			t_object	*obj = at_vector(&engine->scene.objects, i);
			if (obj->type == LIGHT)
			{
				ray.startpos = ray.hitpos;
				ray.ray.x = obj->data.light.coordinates.x - ray.startpos.x;
				ray.ray.y = obj->data.light.coordinates.y - ray.startpos.y;
				ray.ray.z = obj->data.light.coordinates.z - ray.startpos.z;
				ray.maxlen = vector_normalize(&ray.ray);
				double ratio;
				ratio = 1;
				// We need to implement light correctly here
				if (trace_ray(engine, &ray) == -1)
				{
					ratio = ratio  * obj->data.light.ratio;
					light.rgb.r = ft_max(light.rgb.r, obj->data.light.color.rgb.r * ratio);
					light.rgb.g = ft_max(light.rgb.g, obj->data.light.color.rgb.g * ratio);
					light.rgb.b = ft_max(light.rgb.b, obj->data.light.color.rgb.b * ratio);
					light = obj->data.light.color;
				}
			}
			light.rgb.r = ft_max(light.rgb.r, engine->scene.ambient_light.color.rgb.r * engine->scene.ambient_light.ratio);
			light.rgb.g = ft_max(light.rgb.g, engine->scene.ambient_light.color.rgb.g * engine->scene.ambient_light.ratio);
			light.rgb.b = ft_max(light.rgb.b, engine->scene.ambient_light.color.rgb.b * engine->scene.ambient_light.ratio);
			++i;
		}
		return (color.color & light.color);
	}
	return (0);
}
