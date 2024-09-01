/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_mtl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 01:33:43 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 01:42:02 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "obj_mtl.h"
#include "object/material.h"

static int	parse_line(t_obj_3d *obj, char *line);
static int	parse_obj_vertice(t_obj_3d *obj);
static int	parse_obj_vertex_normal(t_obj_3d *obj);
static int	parse_obj_texture_coord(t_obj_3d *obj);
static int	parse_obj_space_vertice(t_obj_3d *obj);
static int	parse_obj_polygon(t_obj_3d *obj);

int	parse_obj_mtl(t_obj_mtl *mtl, const char *file)
{
	int		fd;
	char	*line;

	mtl->file_name = ft_strdup(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	init_vector(&mtl->materials, sizeof(t_material_data));
	t_buffer *buf = malloc(sizeof(t_buffer));
	if (buf == NULL)
		return (-1);
	ft_memset(buf, 0, sizeof(t_buffer));
	line = get_next_line_ptr(fd, buf);
	while (line)
	{
		line = ft_strtok(line, "\r");
		if (parse_line(mtl, line) == -1)
		{
			close(fd);
			return (-1);
		}
		line = get_next_line_ptr(fd, buf);
	}
	free(line);
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
