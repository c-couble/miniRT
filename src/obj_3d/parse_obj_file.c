/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:21:11 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/13 03:44:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "get_next_line_utils.h"
#include "obj_3d.h"
#include "ft_io.h"
#include "ft_string.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "vec3.h"
#include "object/parse_util.h"
#include "float.h"
#include "vec4.h"
#include "vector.h"
#include "ft_mem.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

static int	parse_line(t_engine *engine, t_obj_3d *obj, char *line);
static int	parse_obj_mtl(t_engine *engine, t_obj_3d *obj, char *save);
static int	parse_use_mtl(t_engine *engine, t_obj_3d *obj, char *save);
static int	parse_obj_vertice(t_engine *engine, t_obj_3d *obj, char *save);
static int	parse_obj_vertex_normal(t_engine *engine, t_obj_3d *obj, char *save);
static int	parse_obj_texture_coord(t_engine *engine, t_obj_3d *obj, char *save);
static int	parse_obj_space_vertice(t_engine *engine, t_obj_3d *obj, char *save);
static int	parse_obj_polygon(t_engine *engine, t_obj_3d *obj, char *save);

int	parse_obj_file(t_engine *engine, t_obj_3d *obj, char *file)
{
	int		fd;
	char	*line;

	obj->file_name = ft_strdup(file);
	obj->mtl = NULL;
	obj->current_material = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	init_vector(&obj->vertices, sizeof(t_vec4));
	init_vector(&obj->texture_coordinates, sizeof(t_vec3));
	init_vector(&obj->vertex_normals, sizeof(t_vec3));
	init_vector(&obj->space_vertices, sizeof(t_vec3));
	init_vector(&obj->faces, sizeof(t_polygon));
	t_buffer *buf = malloc(sizeof(t_buffer));
	if (buf == NULL)
		return (-1);
	ft_memset(buf, 0, sizeof(t_buffer));
	line = get_next_line_ptr(fd, buf, "\n\r");
	while (line)
	{
		if (parse_line(engine, obj, line) == -1)
		{
			close(fd);
			return (-1);
		}
		line = get_next_line_ptr(fd, buf, "\n\r");
	}
	free(line);
	if (errno)
	{
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	build_obj_cache(obj);
	return (0);
}

static int	parse_line(t_engine *engine, t_obj_3d *obj, char *line)
{
	static int	(*funcs[])(t_engine *engine, t_obj_3d *data, char *save) = {
	[MTLLIB] = parse_obj_mtl,
	[USEMTL] = parse_use_mtl,
	[VERTICE] = parse_obj_vertice,
	[VERTEX_NORMAL] = parse_obj_vertex_normal,
	[TEXTURE_COORD] = parse_obj_texture_coord,
	[SPACE_VERTICE] = parse_obj_space_vertice,
	[POLYGON] = parse_obj_polygon,
	};
	static char	*data[] = {
	[MTLLIB] = "mtllib",
	[USEMTL] = "usemtl",
	[VERTICE] = "v",
	[VERTEX_NORMAL] = "vn",
	[TEXTURE_COORD] = "vt",
	[SPACE_VERTICE] = "vp",
	[POLYGON] = "f",
	};
	char	*arg;
	char	*save;

	arg = ft_strtok_r(line, " \t", &save);
	if (arg == NULL || arg[0] == '#')
		return (0);
	int i = 0;
	while (i <= POLYGON)
	{
		if (ft_strcmp(arg, data[i]) == 0)
			return (funcs[i](engine, obj, save));
		++i;
	}
	return (0);
}

static int	parse_obj_mtl(t_engine *engine, t_obj_3d *obj, char *line)
{
	obj->mtl = parse_obj_mtl_if_needed(engine, line);
	if (obj->mtl == NULL)
		return (-1);
	return (0);
}

static int	parse_use_mtl(t_engine *engine, t_obj_3d *obj, char *line)
{
	size_t			i;
	t_material_data	*material;

	(void) engine;
	if (obj->mtl == NULL)
		return (-1);
	i = 0;
	while (i < obj->mtl->materials.size)
	{
		material = at_vector(&obj->mtl->materials, i);
		if (ft_strcmp(material->name, line) == 0)
		{
			obj->current_material = material;
			return (0);
		}
		++i;
	}
	return (-1);
}

static int	parse_obj_vertice(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec4	vec;
	char	*save;

	(void) engine;
	if (parse_double(&vec.x, ft_strtok_r(line, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.z, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.w, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.w = 1;
	if (add_vector(&obj->vertices, &vec, 1) == -1)
		return (-1);
	return (0);
}
static int	parse_obj_vertex_normal(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec3	vec;
	char	*save;

	(void) engine;
	if (parse_double(&vec.x, ft_strtok_r(line, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.z, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (add_vector(&obj->vertex_normals, &vec, 1) == -1)
		return (-1);
	return (0);
}
static int	parse_obj_texture_coord(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec3	vec;
	char	*save;

	(void) engine;
	if (parse_double(&vec.x, ft_strtok_r(line, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.y = 0;
	if (parse_double(&vec.z, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.z = 0;
	if (add_vector(&obj->texture_coordinates, &vec, 1) == -1)
		return (-1);
	return (0);
}
static int	parse_obj_space_vertice(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec3	vec;
	char	*save;

	(void) engine;
	if (parse_double(&vec.x, ft_strtok_r(line, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.y = 0;
	if (parse_double(&vec.z, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.z = 0;
	if (add_vector(&obj->texture_coordinates, &vec, 1) == -1)
		return (-1);
	return (0);
}

static int	parse_polygon_point(t_polygon_point *point, char *arg)
{
	if (arg == NULL)
		return (-1);
	point->vertice_id = ft_atoi(arg);
	point->texture_id = -1;
	point->normal_id = -1;
	arg = ft_strchr(arg, '/');
	if (arg == NULL)
		return (0);
	++arg;
	if (*arg != '/')
		point->texture_id = ft_atoi(arg);
	arg = ft_strchr(arg, '/');
	if (arg == NULL)
		return (0);
	++arg;
	point->normal_id = ft_atoi(arg);
	return (0);
}

static int	parse_obj_polygon(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_polygon	poly;
	char		*save;

	(void) engine;
	poly.material = obj->current_material;
	if (parse_polygon_point(&poly.points[0], ft_strtok_r(line, " \t", &save)) == -1)
		return (-1);
	if (parse_polygon_point(&poly.points[1], ft_strtok_r(NULL, " \t", &save)) == -1)
		return (-1);
	if (parse_polygon_point(&poly.points[2], ft_strtok_r(NULL, " \t", &save)) == -1)
		return (-1);
	if (add_vector(&obj->faces, &poly, 1) == -1)
		return (-1);
	return (0);
}
