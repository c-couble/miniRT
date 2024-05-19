/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/15 19:21:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "vector3d.h"
#include "object.h"
#include "object/parse_util.h"
#include "float.h"
#include <stdio.h>

int	parse_camera(t_object_data *data)
{
	if (parse_vector3d(&data->camera.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->camera.orientation) == -1)
		return (-1);
	if (parse_double(&data->camera.fov, ft_strtok(NULL, " \t"), 0, 180) == -1)
		return (-1);
	return (0);
}
