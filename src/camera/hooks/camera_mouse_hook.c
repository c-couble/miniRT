/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mouse_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:02:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/30 08:50:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "object/camera.h"
#include "quaternion.h"

void	camera_mouse_hook(t_engine *engine)
{
	t_camera	*cam;
	const int	x_diff = engine->mlx.x - engine->mlx.old_x;
	const int	y_diff = engine->mlx.y - engine->mlx.old_y;

	cam = &engine->scene.camera;
	if (cam->locked || (x_diff == 0 && y_diff == 0))
		return ;
	quaternion_rotate(&cam->front, &cam->right, y_diff / 100., &cam->front);
	quaternion_rotate(&cam->up, &cam->right, y_diff / 100., &cam->up);
	vec3_normalize(&cam->front);
	vec3_normalize(&cam->up);
	quaternion_rotate(&cam->front, &cam->up, x_diff / 100., &cam->front);
	quaternion_rotate(&cam->right, &cam->up, x_diff / 100., &cam->right);
	vec3_normalize(&cam->front);
	vec3_normalize(&cam->right);
	engine->scene.camera.should_render = 1;
}
