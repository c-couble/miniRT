/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mouse_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:02:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/06 21:56:05 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"
#include "quaternion.h"
#include "vec3.h"

void	camera_mouse_hook(t_engine *engine)
{
	t_camera	*cam;
	t_vec3		up;
	double		x_diff;
	double		y_diff;

	cam = &engine->scene.camera;
	x_diff = (engine->mlx.x - engine->mlx.old_x) / 100.;
	y_diff = (engine->mlx.y - engine->mlx.old_y) / 100.;
	if (cam->locked || (x_diff == 0 && y_diff == 0))
		return ;
	quaternion_rotate(&cam->front, &cam->right, -y_diff, &cam->front);
	vec3_create(0, 0, 1, &up);
	quaternion_rotate(&cam->front, &up, -x_diff, &cam->front);
	quaternion_rotate(&cam->right, &up, -x_diff, &cam->right);
	vec3_cross_product(&cam->right, &cam->front, &cam->up);
	engine->scene.camera.should_render = 1;
}
