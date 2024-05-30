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
#include "vector.h"
#include "vector3d.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t	trace_ray(t_engine *engine, t_vector3d *ray);

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
			t_vector3d	vec;
			yaw_pitch_to_vector(&vec, yaw, pitch);
			engine->mlx.addr[(i * engine->mlx.width) + j].color = trace_ray(engine, &vec);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}

static uint32_t	trace_ray(t_engine *engine, t_vector3d *ray)
{
	size_t		i;
	t_object	*obj;

	i = 0;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == SPHERE)
		{
			t_vector3d	p;
			p.x = engine->scene.camera.coordinates.x - obj->data.sphere.coordinates.x;
			p.y = engine->scene.camera.coordinates.y - obj->data.sphere.coordinates.y;
			p.z = engine->scene.camera.coordinates.z - obj->data.sphere.coordinates.z;
			double a = powl(ray->x, 2) + powl(ray->y, 2) + powl(ray->z, 2);
			double b = 2 * (p.x * ray->x + p.y * ray->y + p.z * ray->z);
			double c = (powl(p.x, 2) + powl(p.y, 2) + powl(p.z, 2)) - powl(obj->data.sphere.diameter / 2, 2);
			double d = powl(b, 2) - (4 * a * c);
			if (d >= 0)
			{
				double r1 = (-b - sqrt(d)) / (2 * a);
				double r2 = (-b + sqrt(d)) / (2 * a);
				double r;
				if (r1 < 0)
					r = r2;
				else if (r2 < 0)
					r = r1;
				else
				{
					if (r1 > r2)
						r = r2;
					else
						r = r1;
				}
				if (r < 0)
					continue;
				return (obj->data.sphere.color.color);
			}
		}
		++i;
	}
	return (0);
}
