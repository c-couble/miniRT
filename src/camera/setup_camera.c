/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/17 01:30:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"
#include "defines.h"
#include <math.h>

static void	setup_projection(t_camera *camera, double ratio);
static void	setup_view(t_camera *camera);

void	setup_camera(t_engine *engine)
{
	const double	ratio = (double) engine->mlx.width / engine->mlx.height;
	t_camera		*cam;

	cam = &engine->scene.camera;
	setup_projection(cam, ratio);
	setup_view(cam);
	mat4_multiply(&cam->inverse_projection, &cam->inverse_view, &cam->final);
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
	t_vec3	up;
	t_vec3	forward;
	t_vec3	right;

	vec3_create(0, 0, 1, &up);
	forward = camera->orientation;
	vec3_scale(&forward, -1);
	vec3_cross_product(&up, &forward, &right);
	camera->view.matrix[0] = right.x;
	camera->view.matrix[1] = forward.x;
	camera->view.matrix[2] = up.x;
	camera->view.matrix[3] = camera->coordinates.x;
	camera->view.matrix[4] = right.y;
	camera->view.matrix[5] = forward.y;
	camera->view.matrix[6] = up.y;
	camera->view.matrix[7] = camera->coordinates.y;
	camera->view.matrix[8] = right.z;
	camera->view.matrix[9] = forward.z;
	camera->view.matrix[10] = up.z;
	camera->view.matrix[11] = camera->coordinates.z;
	camera->view.matrix[12] = 0;
	camera->view.matrix[13] = 0;
	camera->view.matrix[14] = 0;
	camera->view.matrix[15] = 1;
	mat4_inverse(&camera->view, &camera->inverse_view);
}