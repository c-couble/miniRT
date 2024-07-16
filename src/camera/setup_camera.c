/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:13:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/16 20:24:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "object/camera.h"
#include "defines.h"
#include <math.h>
#include <stdio.h>

static void	setup_projection(t_camera *camera);
static void	setup_view(t_camera *camera);

void	setup_camera(t_camera *camera)
{
	setup_projection(camera);
	setup_view(camera);
	mat4_multiply(&camera->inverse_projection, &camera->inverse_view, &camera->final);
	printf("FINAL MATRIX\n");
	mat4_print(&camera->final);
}

static void	setup_projection(t_camera *camera)
{
	const double fov_rad = 1 / tan((camera->fov * (M_PI / 180)) / 2);

	camera->projection.matrix[0] = (1 / ((double) SCREEN_WIDTH / SCREEN_HEIGHT)) * fov_rad;
	camera->projection.matrix[1] = 0;
	camera->projection.matrix[2] = 0;
	camera->projection.matrix[3] = 0;
	camera->projection.matrix[4] = 0;
	camera->projection.matrix[5] = 1;
	camera->projection.matrix[6] = 0;
	camera->projection.matrix[7] = 0;
	camera->projection.matrix[8] = 0;
	camera->projection.matrix[9] = 0;
	camera->projection.matrix[10] = fov_rad;
	camera->projection.matrix[11] = 0;
	camera->projection.matrix[12] = 0;
	camera->projection.matrix[13] = 0;
	camera->projection.matrix[14] = 0;
	camera->projection.matrix[15] = 1;
	camera->inverse_projection = camera->projection;
	printf("PROJ MATRIX\n");
	mat4_print(&camera->projection);
	printf("END PROJ MATRIX\n");
	printf("START INVERSION\n");
	mat4_inverse(&camera->projection, &camera->inverse_projection);
	printf("END INVERSION\n");
	printf("INVERSE PROJ\n");
	mat4_print(&camera->inverse_projection);
	printf("INVERSE END\n");


}

static void	setup_view(t_camera *camera)
{
	t_vec3	up;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	target;

	target = camera->orientation;
	vec3_create(0, 0, 1, &up);
	forward = target;
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
	printf("VIEW MATRIX\n");
	mat4_print(&camera->view);
	printf("END VIEW MATRIX\n");
	printf("START INVERSION\n");
	mat4_inverse(&camera->view, &camera->inverse_view);
	printf("END INVERSION\n");
	printf("INVERSE\n");
	mat4_print(&camera->inverse_view);
	printf("INVERSE END\n");
}


