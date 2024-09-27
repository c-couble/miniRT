/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 01:49:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine.h"
#include "object/camera.h"

static void	setup_projection(t_camera *camera, double ratio);

void	setup_camera(t_engine *engine)
{
	const double	ratio = (double) engine->mlx.width / engine->mlx.height;
	t_camera		*cam;

	cam = &engine->scene.camera;
	setup_projection(cam, ratio);
	mat4_view(&cam->view, &cam->front, &cam->up, &cam->coordinates);
	mat4_inverse(&cam->view, &cam->inverse_view);
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
