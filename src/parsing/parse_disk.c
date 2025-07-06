/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:41:56 by lespenel          #+#    #+#             */
/*   Updated: 2025/07/06 23:11:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "color.h"
#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "util.h"
#include "vec3.h"

int	parse_disk(t_engine *engine, t_object_data *data)
{
	char	*arg;

	(void) engine;
	if (parse_vector3d(&data->disk.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->disk.normal) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->disk.diameter, arg, 0, DBL_MAX) == -1)
		return (-1);
	data->disk.radius = data->disk.diameter / 2;
	data->disk.radiussq = data->disk.radius * data->disk.radius;
	if (parse_color(&data->disk.color) == -1)
		return (-1);
	data->disk.theta = get_theta_axis(&data->disk.normal, &data->disk.rot_axis);
	return (0);
}
