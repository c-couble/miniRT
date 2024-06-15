/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:24:31 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "vec3.h"
#include "object.h"
#include "object/parse_util.h"
#include "float.h"
#include <math.h>
#include <stdio.h>

static double	ft_acos(double x);

int	parse_camera(t_object_data *data)
{
	double	tmp;

	if (parse_vector3d(&data->camera.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->camera.orientation) == -1)
		return (-1);
	data->camera.pitch = asin(data->camera.orientation.z);
	tmp = cos(data->camera.pitch);
	if (data->camera.orientation.x > 0)
	{
		data->camera.yaw = ft_acos(data->camera.orientation.x / tmp);
		if (data->camera.orientation.y < 0)
			data->camera.yaw *= -1;
	}
	else
		data->camera.yaw = ft_acos(data->camera.orientation.y / tmp) + M_PI_2;
	printf("pitch %lf yaw %lf\n", data->camera.pitch, data->camera.yaw);
	if (parse_double(&data->camera.fov, ft_strtok(NULL, " \t"), 0, 180) == -1)
		return (-1);
	return (0);
}

static double	ft_acos(double x)
{
	if (x < -1)
		return (acos(-1));
	if (x > 1)
		return (acos(1));
	return (acos(x));
}
