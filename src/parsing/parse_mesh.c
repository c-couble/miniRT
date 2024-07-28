/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:00:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/28 01:20:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_string.h"
#include "mat4.h"
#include "mlx_wrapper.h"
#include "obj_3d.h"
#include "object.h"
#include "vec3.h"
#include "float.h"
#include "object/parse_util.h"
#include "vec4.h"
#include <stdlib.h>
#include <stdio.h>

static int	read_obj_and_position(t_engine *engine, t_object_data *data);

int	parse_mesh(t_engine *engine, t_object_data *data)
{
	char	*arg;

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

static void	create_transformation_matrix(t_mat4 *mat, t_object_data *data);

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
	size_t	i;
	i = 0;
	t_mat4	transformation;
	create_transformation_matrix(&transformation, data);
	while (i < data->mesh.obj_3d->vertices.size)
	{
		t_vec3	*vec = at_vector(&data->mesh.obj_3d->vertices, i);
		t_vec4	vec4;
		vec4_create(vec, 1, &vec4);
		vec4_mat4_mult(&vec4, &transformation, &vec4);
		vec->x = vec4.x;
		vec->y = vec4.y;
		vec->z = vec4.z;
		++i;
	}
	return (0);
}

static void	create_transformation_matrix(t_mat4 *mat, t_object_data *data)
{
	mat->matrix[0] = data->mesh.scale;
	mat->matrix[1] = 0;
	mat->matrix[2] = 0;
	mat->matrix[3] = 0;
	mat->matrix[4] = 0;
	mat->matrix[5] = data->mesh.scale;
	mat->matrix[6] = 0;
	mat->matrix[7] = 0;
	mat->matrix[8] = 0;
	mat->matrix[9] = 0;
	mat->matrix[10] = data->mesh.scale;
	mat->matrix[11] = 0;
	mat->matrix[12] = data->mesh.pos.x;
	mat->matrix[13] = data->mesh.pos.y;
	mat->matrix[14] = data->mesh.pos.z;
	mat->matrix[15] = 1;
}
