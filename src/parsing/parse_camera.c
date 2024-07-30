/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 07:56:08 by ccouble          ###   ########.fr       */
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
	t_vec3	forward;

	if (parse_vector3d(&data->camera.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->camera.front) == -1)
		return (-1);
	if (parse_double(&data->camera.fov, ft_strtok(NULL, " \t"), 0, 180) == -1)
		return (-1);
	vec3_create(0, 0, 1, &data->camera.up);
	forward = data->camera.front;
	vec3_scale(&forward, -1);
	vec3_cross_product(&data->camera.up, &forward, &data->camera.right);
	data->camera.locked = 0;
	data->camera.pixel_square_size = DEFAULT_RAY_SIZE;
	return (0);
}
