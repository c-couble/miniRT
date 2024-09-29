/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:00:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 05:47:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdlib.h>
#include "engine.h"
#include "ft_string.h"
#include "object.h"
#include "object/mesh.h"
#include "object/parse_util.h"
#include "util.h"

static int	read_obj_data(t_engine *engine, t_object_data *data, char *arg);
static void	set_cached_triangles_aabb(t_mesh *mesh);

int	parse_mesh(t_engine *engine, t_object_data *data)
{
	char	*arg;
	t_mesh	*mesh;

	(void) data;
	(void) engine;
	mesh = &data->mesh;
	mesh->cache = NULL;
	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	if (read_obj_data(engine, data, arg) == -1)
		return (-1);
	set_cached_triangles_aabb(mesh);
	mesh->bvh = init_bvh_mesh(mesh->cache, mesh->triangles);
	if (mesh->bvh == NULL)
	{
		free(mesh->cache);
		return (-1);
	}
	return (0);
}

static int	read_obj_data(t_engine *engine, t_object_data *data, char *obj)
{
	char	*arg;

	if (parse_vector3d(&data->mesh.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->mesh.front) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->mesh.up) == -1)
		return (-1);
	if (double_equals(vec3_dot(&data->mesh.front, &data->mesh.up), 0) != 1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->mesh.scale, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	data->mesh.obj_3d = parse_obj_if_needed(engine, obj);
	if (data->mesh.obj_3d == NULL)
		return (-1);
	if (build_obj_cache(&data->mesh) == -1)
		return (-1);
	return (0);
}

static void	set_cached_triangles_aabb(t_mesh *mesh)
{
	size_t	i;

	i = 0;
	while (i < mesh->triangles)
	{
		get_cached_triangle_aabb(&mesh->cache[i], &mesh->cache[i].aabb);
		++i;
	}
}
