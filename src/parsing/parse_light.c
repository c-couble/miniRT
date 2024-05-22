/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/22 03:10:20 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "vector3d.h"
#include "float.h"

int	parse_light(t_object_data *data)
{
	if (parse_vector3d(&data->light.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&data->light.ratio, ft_strtok(NULL, " \t"), 0, 1) == -1)
		return (-1);
	if (parse_color(&data->light.color) == -1)
		return (-1);
	return (0);
}
