/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/15 13:52:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

static void	setup_view(t_camera *camera);

void	setup_camera(t_engine *engine)
{
	t_camera		*cam;

	cam = &engine->scene.camera;
	setup_view(cam);
	mat4_multiply(&cam->inverse_projection, &cam->inverse_view, &cam->final);
	cam->frame_width = engine->mlx.width / cam->pixel_square_size + 1;
	cam->frame_height = engine->mlx.height / cam->pixel_square_size + 1;
}

static void	setup_view(t_camera *camera)
{
	t_vec3	forward;

	forward = camera->front;
	vec3_scale(&forward, -1);
	camera->view.matrix[0] = camera->right.x;
	camera->view.matrix[1] = forward.x;
	camera->view.matrix[2] = camera->up.x;
	camera->view.matrix[3] = camera->coordinates.x;
	camera->view.matrix[4] = camera->right.y;
	camera->view.matrix[5] = forward.y;
	camera->view.matrix[6] = camera->up.y;
	camera->view.matrix[7] = camera->coordinates.y;
	camera->view.matrix[8] = camera->right.z;
	camera->view.matrix[9] = forward.z;
	camera->view.matrix[10] = camera->up.z;
	camera->view.matrix[11] = camera->coordinates.z;
	camera->view.matrix[12] = 0;
	camera->view.matrix[13] = 0;
	camera->view.matrix[14] = 0;
	camera->view.matrix[15] = 1;
	mat4_inverse(&camera->view, &camera->inverse_view);
}
