/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/23 06:38:49 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object.h"
#include "vector.h"
#include "vector3d.h"
#include <math.h>
#include <stdio.h>

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	double	hinc = (engine->scene.camera.fov / engine->mlx.width) * (M_PI / 180);
	double	vfov = engine->scene.camera.fov / ((double)engine->mlx.width / engine->mlx.height);
	double	vinc = (vfov / engine->mlx.height) * (M_PI / 180);

	i = 0;
	printf("START FRAME\n\n");
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
			for (int k = 1; k < 500; ++k)
			{
				t_vector3d	vec2;
				vec2.x = vec.x * k;
				vec2.y = vec.y * k;
				vec2.z = vec.z * k;
				for (size_t l = 0; l < engine->scene.objects.size; ++l)
				{
					t_object	*obj = at_vector(&engine->scene.objects, l);
					if (obj->type == SPHERE)
					{
						if (obj->data.sphere.diameter / 2
							>= sqrt(powl(vec2.x - obj->data.sphere.coordinates.x, 2) + powl(vec2.y - obj->data.sphere.coordinates.y, 2) + powl(vec2.z - obj->data.sphere.coordinates.z, 2)))
						{
							engine->mlx.addr[(i * engine->mlx.width) + j].color = obj->data.sphere.color.color;
						}
					}
				}
			}
			//if (sqrt(powl((long)j - 1000, 2) + powl((long)i - 500, 2)) < 100)
			//	engine->mlx.addr[(i * engine->mlx.width) + j].color = 0xff0000;
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}
