/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 16:57:55 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_string.h"
#include "object.h"
#include "object/camera.h"
#include "object/parse_util.h"
#include "vec3.h"

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
	return (0);
}
