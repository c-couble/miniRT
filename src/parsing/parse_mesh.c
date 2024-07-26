/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:00:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:45:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_string.h"
#include "obj_3d.h"
#include "object.h"
#include "vec3.h"
#include "float.h"
#include "object/parse_util.h"
#include <stdlib.h>
#include <stdio.h>

static int	read_obj_and_position(t_engine *engine, t_object_data *data);

int	parse_mesh(t_engine *engine, t_object_data *data)
{
	char	*arg;

	printf("arabie\n");
	(void) engine;
	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	data->mesh.name = ft_strdup(arg);
	if (data->mesh.name == NULL)
		return (-2);
	if (read_obj_and_position(engine, data) == -1)
	{
		free(data->mesh.name);
		return (-1);
	}
	return (0);
}

static int	read_obj_and_position(t_engine *engine, t_object_data *data)
{
	char	*arg;

	if (parse_vector3d(&data->mesh.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->mesh.orientation, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->mesh.scale, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	data->mesh.obj_3d = parse_obj_if_needed(engine, data->mesh.name);
	if (data->mesh.obj_3d == NULL)
		return (-1);
	return (0);
}
