/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 18:25:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "object/rgb.h"
#include "vector3d.h"
#include "float.h"
#include <stdio.h>

int	parse_cylinder(t_object_data *data)
{
	if (parse_vector3d(&data->cylinder.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->cylinder.axis, -1, 1) == -1)
		return (-1);
	if (parse_double(&data->cylinder.diameter, ft_strtok(NULL, " \t"), 0, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&data->cylinder.height, ft_strtok(NULL, " \t"), 0, DBL_MAX) == -1)
		return (-1);
	if (parse_rgb(&data->cylinder.color) == -1)
		return (-1);
	printf("cy coord x=%lf y=%lf z=%lf orient x=%lf y=%lf z=%lf diameter %lf height %lf r=%d g=%d b=%d\n",
		data->cylinder.coordinates.x, data->cylinder.coordinates.y,
		data->cylinder.coordinates.z, data->cylinder.axis.x,
		data->cylinder.axis.y, data->cylinder.axis.z,
		data->cylinder.diameter,
		data->cylinder.height, data->cylinder.color.r,
		data->cylinder.color.g, data->cylinder.color.b);
	return (0);
}
