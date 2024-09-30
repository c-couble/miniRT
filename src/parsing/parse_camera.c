/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 09:37:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "defines.h"
#include "engine.h"
#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"

int	parse_camera(t_engine *engine, t_object_data *data)
{
	(void) engine;
	if (parse_vector3d(&data->camera.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->camera.front) == -1)
		return (-1);
	if (parse_double(&data->camera.fov, ft_strtok(NULL, " \t"), 0, 180) == -1)
		return (-1);
	create_camera_vectors(&data->camera);
	data->camera.locked = 0;
	data->camera.pixel_square_size = DEFAULT_RAY_SIZE;
	data->camera.should_render = 1;
	data->camera.sensitivity = SENSITIVITY;
	data->camera.speed = CAMERA_SPEED;
	data->camera.render_type = CLASSIC;
	return (0);
}
