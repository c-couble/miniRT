/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:21:11 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/25 06:10:55 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_3d.h"
#include "ft_io.h"
#include "ft_string.h"
#include "vec3.h"
#include "object/parse_util.h"
#include "float.h"
#include "vec4.h"
#include "vector.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

static int	parse_line(t_obj_3d *obj, char *line);
static int	parse_obj_vertice(t_obj_3d *obj);
static int	parse_obj_vertex_normal(t_obj_3d *obj);
static int	parse_obj_texture_coord(t_obj_3d *obj);
static int	parse_obj_space_vertice(t_obj_3d *obj);
static int	parse_obj_polygon(t_obj_3d *obj);

int	parse_obj_file(t_obj_3d *obj, const char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	init_vector(&obj->vertices, sizeof(t_vec4));
	init_vector(&obj->texture_coordinates, sizeof(t_vec3));
	init_vector(&obj->vertex_normals, sizeof(t_vec3));
	init_vector(&obj->space_vertices, sizeof(t_vec3));
	init_vector(&obj->faces, sizeof(t_polygon));
	line = get_next_line(fd);
	while (line)
	{
		line = ft_strtok(line, "\r");
		if (parse_line(obj, line) == -1)
		{
			close(fd);
			return (-1);
		}
		line = get_next_line(fd);
	}
	if (errno)
	{
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	parse_line(t_obj_3d *obj, char *line)
{
	static int	(*funcs[])(t_obj_3d *data) = {
	[VERTICE] = parse_obj_vertice,
	[VERTEX_NORMAL] = parse_obj_vertex_normal,
	[TEXTURE_COORD] = parse_obj_texture_coord,
	[SPACE_VERTICE] = parse_obj_space_vertice,
	[POLYGON] = parse_obj_polygon,
	};
	static char	*data[] = {
	[VERTICE] = "v",
	[VERTEX_NORMAL] = "vn",
	[TEXTURE_COORD] = "vt",
	[SPACE_VERTICE] = "vp",
	[POLYGON] = "f",
	};
	char	*arg;

	arg = ft_strtok(line, " \t");
	if (arg == NULL || arg[0] == '#')
		return (0);
	int i = 0;
	while (i <= POLYGON)
	{
		if (ft_strcmp(arg, data[i]) == 0)
			return (funcs[i](obj));
		++i;
	}
	return (0);
}

static int	parse_obj_vertice(t_obj_3d *obj)
{
	t_vec4	vec;

	if (parse_double(&vec.x, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.z, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.w, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		vec.w = 1;
	if (add_vector(&obj->vertices, &vec, 1) == -1)
		return (-1);
	return (0);
}
static int	parse_obj_vertex_normal(t_obj_3d *obj)
{
	t_vec3	vec;

	if (parse_double(&vec.x, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.z, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (add_vector(&obj->vertex_normals, &vec, 1) == -1)
		return (-1);
	return (0);
}
static int	parse_obj_texture_coord(t_obj_3d *obj)
{
	t_vec3	vec;

	if (parse_double(&vec.x, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		vec.y = 0;
	if (parse_double(&vec.z, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		vec.z = 0;
	if (add_vector(&obj->texture_coordinates, &vec, 1) == -1)
		return (-1);
	return (0);
}
static int	parse_obj_space_vertice(t_obj_3d *obj)
{
	t_vec3	vec;

	if (parse_double(&vec.x, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		vec.y = 0;
	if (parse_double(&vec.z, ft_strtok(NULL, " \t"), -DBL_MAX, DBL_MAX) == -1)
		vec.z = 0;
	if (add_vector(&obj->texture_coordinates, &vec, 1) == -1)
		return (-1);
	return (0);
}

static int	parse_polygon_point(t_polygon_point *point)
{
	char	*arg;

	arg = ft_strtok(NULL, " \t");
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
static int	parse_obj_polygon(t_obj_3d *obj)
{
	t_polygon	poly;

	if (parse_polygon_point(&poly.points[0]) == -1)
		return (-1);
	if (parse_polygon_point(&poly.points[1]) == -1)
		return (-1);
	if (parse_polygon_point(&poly.points[2]) == -1)
		return (-1);
	if (add_vector(&obj->faces, &poly, 1) == -1)
		return (-1);
	return (0);
}
