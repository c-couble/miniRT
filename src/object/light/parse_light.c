/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 17:35:58 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "vector3d.h"
#include <float.h>
#include <stdio.h>

int	parse_light(t_object_data *data)
{
	if (parse_vector3d(&data->light.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&data->light.ratio, ft_strtok(NULL, " \t"), 0, 1) == -1)
		return (-1);
	if (parse_rgb(&data->light.color) == -1)
		return (-1);
	printf("L coord x=%lf y=%lf z=%lf ratio %lf r=%d g=%d b=%d\n",
		data->light.coordinates.x, data->light.coordinates.y,
		data->light.coordinates.z, data->light.ratio, data->light.color.r,
		data->light.color.g, data->light.color.b);
	return (0);
}
