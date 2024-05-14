/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 08:18:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "vector3d.h"
#include "object.h"
#include "object/parse_util.h"
#include "float.h"
#include <stdio.h>

int	parse_camera(t_object_data *data)
{
	if (parse_vector3d(&data->camera.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->camera.orientation, -1, 1) == -1)
		return (-1);
	if (parse_double(&data->camera.fov, ft_strtok(NULL, " \t"), 0, 180) == -1)
		return (-1);
	printf("C coord x=%lf y=%lf z=%lf orient x=%lf y=%lf z=%lf fov=%lf\n",
		data->camera.coordinates.x, data->camera.coordinates.y,
		data->camera.coordinates.z, data->camera.orientation.x,
		data->camera.orientation.y, data->camera.orientation.z,
		data->camera.fov);
	return (0);
}
