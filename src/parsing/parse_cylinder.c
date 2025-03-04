/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 21:46:32 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdio.h>
#include "engine.h"
#include "ft_string.h"
#include "color.h"
#include "object.h"
#include "object/parse_util.h"
#include "util.h"
#include "vec3.h"

int	parse_cylinder(t_engine *engine, t_object_data *data)
{
	char	*arg;
	t_vec3	tmp;

	(void) engine;
	if (parse_vector3d(&data->cylinder.center, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->cylinder.axis) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->cylinder.diameter, arg, 0, DBL_MAX) == -1)
		return (-1);
	data->cylinder.radius = data->cylinder.diameter / 2;
	data->cylinder.radiussq = data->cylinder.radius * data->cylinder.radius;
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->cylinder.height, arg, 0, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->cylinder.color) == -1)
		return (-1);
	data->cylinder.theta = get_theta_axis(&data->cylinder.axis,
			&data->cylinder.rot_axis);
	tmp = data->cylinder.axis;
	vec3_scale(&tmp, data->cylinder.height / 2);
	vec3_subtract(&data->cylinder.center, &tmp, &data->cylinder.pos);
	return (0);
}
