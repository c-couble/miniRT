/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:03:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/05 01:15:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "color.h"
#include "vector3d.h"
#include "float.h"
#include <stdio.h>

int	parse_paraboloid(t_object_data *data)
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
	return (0);
}
