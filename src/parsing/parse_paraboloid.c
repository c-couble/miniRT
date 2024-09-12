/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:03:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 14:25:36 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "util.h"
#include <stdio.h>

int	parse_paraboloid(t_engine *engine, t_object_data *data)
{
	char	*arg;

	(void) engine;
	if (parse_vector3d(&data->paraboloid.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->paraboloid.axis) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->paraboloid.radius, arg, 0, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->paraboloid.height, arg, 0, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->paraboloid.color) == -1)
		return (-1);
	data->paraboloid.theta = get_theta_axis(&data->paraboloid.axis,
			&data->paraboloid.rot_axis);
	if (data->paraboloid.radius < 0.01)
		data->paraboloid.radius_coef = 0;
	else
	{
		data->paraboloid.radius_coef = data->paraboloid.height
			/ (data->paraboloid.radius * data->paraboloid.radius);
	}
	return (0);
}
