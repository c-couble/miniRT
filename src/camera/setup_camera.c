/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 05:13:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

void	setup_camera(t_engine *engine)
{
	t_camera		*cam;

	cam = &engine->scene.camera;
	mat4_view(&cam->view, &cam->front, &cam->up, &cam->coordinates);
	mat4_inverse(&cam->view, &cam->inverse_view);
	mat4_multiply(&cam->inverse_projection, &cam->inverse_view, &cam->final);
	cam->frame_width = engine->mlx.width / cam->pixel_square_size + 1;
	cam->frame_height = engine->mlx.height / cam->pixel_square_size + 1;
}
