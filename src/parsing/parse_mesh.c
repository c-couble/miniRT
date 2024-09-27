/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:00:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 02:09:11 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine.h"
#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "float.h"

static int	read_obj_data(t_engine *engine, t_object_data *data, char *arg);

int	parse_mesh(t_engine *engine, t_object_data *data)
{
	char	*arg;

	(void) data;
	(void) engine;
	data->mesh.cache = NULL;
	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	if (read_obj_data(engine, data, arg) == -1)
		return (-1);
	return (0);
}

static int	read_obj_data(t_engine *engine, t_object_data *data, char *obj)
{
	char	*arg;

	if (parse_vector3d(&data->mesh.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->mesh.front, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->mesh.up, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->mesh.scale, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	data->mesh.obj_3d = parse_obj_if_needed(engine, obj);
	if (data->mesh.obj_3d == NULL)
		return (-1);
	build_obj_cache(&data->mesh);
	return (0);
}
