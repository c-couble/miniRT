/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/07 15:12:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "color.h"
#include "vector3d.h"
#include "float.h"
#include <stdio.h>

int	parse_cylinder(t_object_data *data)
{
	char	*arg;

	if (parse_vector3d(&data->cylinder.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->cylinder.axis) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->cylinder.diameter, arg, 0, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->cylinder.height, arg, 0, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->cylinder.color) == -1)
		return (-1);
	printf("Cylinder %lf;%lf;%lf axis %lf;%lf;%lf diameter %lf height %lf\n",
		data->cylinder.coordinates.x, data->cylinder.coordinates.y,
		data->cylinder.coordinates.z, data->cylinder.axis.x,
		data->cylinder.axis.y, data->cylinder.axis.z, data->cylinder.diameter,
		data->cylinder.height);
	return (0);
}
