/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 05:36:31 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "ft_string.h"
#include "vec3.h"
#include "object.h"
#include "object/parse_util.h"
#include "float.h"

int	parse_camera(t_object_data *data)
{
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
	data->camera.speed = SPEED;
	return (0);
}
