/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/15 02:00:02 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "color.h"
#include "vec3.h"
#include "float.h"
#include <stdio.h>

int	parse_cylinder(t_object_data *data)
{
	char	*arg;

	if (parse_vector3d(&data->cylinder.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->cylinder.axis) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->cylinder.diameter, arg, 0, DBL_MAX) == -1)
		return (-1);
	data->cylinder.radius = data->cylinder.diameter / 2;
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->cylinder.height, arg, 0, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->cylinder.color) == -1)
		return (-1);
	return (0);
}
