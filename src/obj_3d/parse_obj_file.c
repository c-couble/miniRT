/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:21:11 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/22 16:30:57 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "get_next_line_utils.h"
#include "obj_3d.h"
#include "ft_io.h"
#include "ft_string.h"
#include "vec3.h"
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

static int	prepare_obj(t_obj_3d *obj, char *file);
static int	read_obj_data(t_engine *engine, t_obj_3d *obj, int fd);
static int	parse_line(t_engine *engine, t_obj_3d *obj, char *line);
static int	parse_elem(t_engine *engine, t_obj_3d *data, char *save, int i);

int	parse_obj_file(t_engine *engine, t_obj_3d *obj, char *file)
{
	int		fd;

	if (prepare_obj(obj, file) == -1)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		clear_obj_3d(obj);
		return (-1);
	}
	if (read_obj_data(engine, obj, fd) == -1)
	{
		clear_obj_3d(obj);
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
	{
		clear_obj_3d(obj);
		return (-1);
	}
	build_obj_cache(obj);
	return (0);
}

static int	prepare_obj(t_obj_3d *obj, char *file)
{
	obj->file_name = ft_strdup(file);
	if (obj->file_name == NULL)
		return (-1);
	obj->mtl = NULL;
	obj->current_material = NULL;
	init_vector(&obj->vertices, sizeof(t_vec4));
	init_vector(&obj->texture_coordinates, sizeof(t_vec3));
	init_vector(&obj->vertex_normals, sizeof(t_vec3));
	init_vector(&obj->space_vertices, sizeof(t_vec3));
	init_vector(&obj->faces, sizeof(t_polygon));
	return (0);
}

static int	read_obj_data(t_engine *engine, t_obj_3d *obj, int fd)
{
	t_buffer	*buf;
	char		*line;
	
	buf = malloc(sizeof(t_buffer));
	if (buf == NULL)
		return (-1);
	ft_memset(buf, 0, sizeof(t_buffer));
	line = get_next_line_ptr(fd, buf, "\n\r");
	while (line)
	{
		if (parse_line(engine, obj, line) == -1)
		{
			free(line);
			free(buf);
			return (-1);
		}
		free(line);
		line = get_next_line_ptr(fd, buf, "\n\r");
	}
	free(buf);
	if (errno)
		return (-1);
	return (0);
}

static int	parse_line(t_engine *engine, t_obj_3d *obj, char *line)
{
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
			return (parse_elem(engine, obj, save, i));
		++i;
	}
	return (0);
}

static int	parse_elem(t_engine *engine, t_obj_3d *data, char *save, int i)
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
	
	return (funcs[i](engine, data, save));
}
