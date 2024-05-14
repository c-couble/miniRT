/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 17:43:58 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "object/rgb.h"
#include "vector3d.h"
#include <float.h>
#include <stdio.h>

int	parse_sphere(t_object_data *data)
{
	if (parse_vector3d(&data->sphere.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&data->sphere.diameter, ft_strtok(NULL, " \t"), 0, DBL_MAX) == -1)
		return (-1);
	if (parse_rgb(&data->sphere.color) == -1)
		return (-1);
	printf("S coord x=%lf y=%lf z=%lf diameter %lf r=%d g=%d b=%d\n",
		data->sphere.coordinates.x, data->sphere.coordinates.y,
		data->sphere.coordinates.z, data->sphere.diameter, data->sphere.color.r,
		data->sphere.color.g, data->sphere.color.b);
	return (0);
}
