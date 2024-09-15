/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/15 11:45:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "defines.h"
#include "ft_string.h"
#include "math.h"
#include "object.h"
#include "object/camera.h"
#include "object/parse_util.h"
#include "vec3.h"

static void	get_perspective(t_camera *camera);

int	parse_camera(t_engine *engine, t_object_data *data)
{
	(void) engine;
	if (parse_vector3d(&data->camera.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->camera.front) == -1)
		return (-1);
	if (parse_double(&data->camera.fov, ft_strtok(NULL, " \t"), 0, 180) == -1)
		return (-1);
	data->camera.ratio = (double)SCREEN_WIDTH / SCREEN_HEIGHT;
	create_camera_vectors(&data->camera);
	get_perspective(&data->camera);
	data->camera.locked = 0;
	data->camera.pixel_square_size = DEFAULT_RAY_SIZE;
	data->camera.should_render = 1;
	data->camera.sensitivity = SENSITIVITY;
	data->camera.speed = SPEED;
	data->camera.render_type = CLASSIC;
	return (0);
}

static void	get_perspective(t_camera *camera)
{
	const double	fov_rad = camera->fov * (M_PI / 180.0);
	const double	tan_half_fov = tan(fov_rad / 2.0);
	const double	far = FAR_PLANE;
	const double	near = NEAR_PLANE;
	const double	far_minus_near = far - near;

	camera->perspective.matrix[0] = 1.0 / (camera->ratio * tan_half_fov);
	camera->perspective.matrix[1] = 0.0;
	camera->perspective.matrix[2] = 0.0;
	camera->perspective.matrix[3] = 0.0;
	camera->perspective.matrix[4] = 0.0;
	camera->perspective.matrix[5] = 0.0;
	camera->perspective.matrix[6] = -far / far_minus_near;
	camera->perspective.matrix[7] = -far * near / far_minus_near;
	camera->perspective.matrix[8] = 0.0;
	camera->perspective.matrix[9] = 1.0 / tan_half_fov;
	camera->perspective.matrix[10] = 0.0;
	camera->perspective.matrix[11] = 0.0;
	camera->perspective.matrix[12] = 0.0;
	camera->perspective.matrix[13] = 0.0;
	camera->perspective.matrix[14] = -1.0;
	camera->perspective.matrix[15] = 0.0;
}
