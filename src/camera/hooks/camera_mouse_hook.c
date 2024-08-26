/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mouse_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:02:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 03:01:53 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
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
	x_diff = engine->scene.camera.sensitivity
		* (engine->mlx.x - engine->mlx.old_x) / 2500.;
	y_diff = engine->scene.camera.sensitivity
		* (engine->mlx.y - engine->mlx.old_y) / 2500.;
	if (engine->mlx.focused == 0 || cam->locked || (x_diff == 0 && y_diff == 0))
		return ;
	quaternion_rotate(&cam->front, &cam->right, -y_diff, &cam->front);
	vec3_create(0, 0, 1, &up);
	quaternion_rotate(&cam->front, &up, -x_diff, &cam->front);
	quaternion_rotate(&cam->right, &up, -x_diff, &cam->right);
	vec3_cross_product(&cam->right, &cam->front, &cam->up);
	mlx_mouse_move(engine->mlx.mlx, engine->mlx.mlx_window,
		engine->mlx.width / 2, engine->mlx.height / 2);
	engine->mlx.x = engine->mlx.width / 2;
	engine->mlx.y = engine->mlx.height / 2;
	engine->scene.camera.should_render = 1;
}
