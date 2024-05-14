/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 18:12:55 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "object/rgb.h"
#include "vector3d.h"
#include "float.h"
#include <stdio.h>

int	parse_plane(t_object_data *data)
{
	if (parse_vector3d(&data->plane.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->plane.orientation, -1, 1) == -1)
		return (-1);
	if (parse_rgb(&data->plane.color) == -1)
		return (-1);
	printf("pl coord x=%lf y=%lf z=%lf orient x=%lf y=%lf z=%lf r=%d g=%d b=%d\n",
		data->plane.coordinates.x, data->plane.coordinates.y,
		data->plane.coordinates.z, data->plane.orientation.x,
		data->plane.orientation.y, data->plane.orientation.z,
		data->plane.color.r,
		data->plane.color.g, data->plane.color.b);
	return (0);
}
