/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/15 12:56:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine.h"
#include "object/camera.h"

static void	setup_projection(t_camera *camera, double ratio);
static void	setup_view(t_camera *camera);

void	setup_camera(t_engine *engine)
{
	t_camera		*cam;

	cam = &engine->scene.camera;
	setup_projection(cam, engine->mlx.aspect);
	setup_view(cam);
	mat4_multiply(&cam->inverse_projection, &cam->inverse_view, &cam->final);
	cam->frame_width = engine->mlx.width / cam->pixel_square_size + 1;
	cam->frame_height = engine->mlx.height / cam->pixel_square_size + 1;
}

static void	setup_projection(t_camera *cam, double ratio)
{
	const double	fov_rad = 1 / tan((cam->fov * (M_PI / 180)) / 2);

	cam->projection.matrix[0] = (1 / ratio) * fov_rad;
	cam->projection.matrix[1] = 0;
	cam->projection.matrix[2] = 0;
	cam->projection.matrix[3] = 0;
	cam->projection.matrix[4] = 0;
	cam->projection.matrix[5] = 1;
	cam->projection.matrix[6] = 0;
	cam->projection.matrix[7] = 0;
	cam->projection.matrix[8] = 0;
	cam->projection.matrix[9] = 0;
	cam->projection.matrix[10] = fov_rad;
	cam->projection.matrix[11] = 0;
	cam->projection.matrix[12] = 0;
	cam->projection.matrix[13] = 0;
	cam->projection.matrix[14] = 0;
	cam->projection.matrix[15] = 1;
	cam->inverse_projection = cam->projection;
	mat4_inverse(&cam->projection, &cam->inverse_projection);
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
