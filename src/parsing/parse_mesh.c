/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:00:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/23 05:55:45 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "vec3.h"
#include "float.h"
#include "object/parse_util.h"
#include <stdio.h>

int	parse_mesh(t_object_data *data)
{
	char	*arg;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	data->mesh.name = ft_strdup(arg);
	if (data->mesh.name == NULL)
		return (-2);
	if (parse_vector3d(&data->mesh.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->mesh.orientation, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->mesh.scale, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	return (0);
}
