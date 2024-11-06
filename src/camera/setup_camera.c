/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/11/04 02:02:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "engine.h"
#include "object/camera.h"

static void	get_cam_view(t_mat4 *mat, t_vec3 *front, t_vec3 *up, t_vec3 *pos);

void	setup_camera(t_engine *engine)
{
	t_camera		*cam;

	cam = &engine->scene.camera;
	get_cam_view(&cam->view, &cam->front, &cam->up, &cam->coordinates);
	mat4_inverse(&cam->view, &cam->inverse_view);
	if (engine->scene.camera.save)
		mat4_multiply(&cam->inv_proj_file, &cam->inverse_view, &cam->final);
	else
		mat4_multiply(&cam->inv_projection, &cam->inverse_view, &cam->final);
	if (engine->scene.camera.save)
	{
		printf("Starting high quality frame (px:%d,%d)...\n",
			engine->render_width, engine->render_height);
		engine->scene.camera.frame_height = engine->render_height;
		engine->scene.camera.frame_width = engine->render_width;
	}
	else
	{
		cam->frame_width = engine->mlx.width / cam->pixel_square_size + 1;
		cam->frame_height = engine->mlx.height / cam->pixel_square_size + 1;
	}
}

static void	get_cam_view(t_mat4 *mat, t_vec3 *front, t_vec3 *up, t_vec3 *pos)
{
	t_vec3	right;
	t_vec3	forward;

	vec3_cross(front, up, &right);
	forward = *front;
	vec3_scale(&forward, -1);
	mat->matrix[0] = right.x;
	mat->matrix[1] = forward.x;
	mat->matrix[2] = up->x;
	mat->matrix[3] = 0;
	mat->matrix[4] = right.y;
	mat->matrix[5] = forward.y;
	mat->matrix[6] = up->y;
	mat->matrix[7] = 0;
	mat->matrix[8] = right.z;
	mat->matrix[9] = forward.z;
	mat->matrix[10] = up->z;
	mat->matrix[11] = 0;
	mat->matrix[12] = pos->x;
	mat->matrix[13] = pos->y;
	mat->matrix[14] = pos->z;
	mat->matrix[15] = 1;
}
