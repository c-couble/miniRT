/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 01:33:43 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/13 09:18:37 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "engine.h"
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "get_next_line_utils.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "vector.h"

static int	prepare_mtl(t_obj_mtl *mtl, char *file);
static int	read_mtl_data(t_engine *engine, t_obj_mtl *mtl, int fd);
static int	parse_line(t_engine *engine, t_obj_mtl *obj, char *line);
static int	parse_elem(t_engine *engine, t_obj_mtl *data, char *save, int i);

int	parse_mtl_file(t_engine *engine, t_obj_mtl *mtl, char *file)
{
	int		fd;

	if (prepare_mtl(mtl, file) == -1)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		clear_mtl(mtl);
		return (-1);
	}
	if (read_mtl_data(engine, mtl, fd) == -1)
	{
		clear_mtl(mtl);
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
	{
		clear_mtl(mtl);
		return (-1);
	}
	return (0);
}

static int	prepare_mtl(t_obj_mtl *mtl, char *file)
{
	mtl->file_name = ft_strdup(file);
	if (mtl->file_name == NULL)
		return (-1);
	init_vector(&mtl->materials, sizeof(t_material_data));
	return (0);
}

static int	read_mtl_data(t_engine *engine, t_obj_mtl *mtl, int fd)
{
	char		*line;
	t_buffer	*buf;

	buf = malloc(sizeof(t_buffer));
	if (buf == NULL)
		return (-1);
	ft_memset(buf, 0, sizeof(t_buffer));
	line = get_next_line_ptr(fd, buf, "\n\r");
	while (line)
	{
		if (parse_line(engine, mtl, line) == -1)
		{
			free(buf);
			free(line);
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

static int	parse_line(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	static char	*data[] = {
	[NEWMTL] = "newmtl", [KA] = "Ka",
	[KD] = "Kd",
	[KS] = "Ks", [TF] = "Tf", [ILLUM] = "illum", [DISSOLVE] = "d",
	[NS] = "Ns",
	[NI] = "Ni",
	[MAP_BUMP] = "map_Bump", [MAP_KD] = "map_Kd",
	[REFLECTION] = "reflection",
	[REFRACTION] = "refraction", [REFRACTION_BLEND] = "refraction_blend",
	};
	char		*arg;
	char		*save;
	int			i;

	arg = ft_strtok_r(line, " \t", &save);
	if (arg == NULL || arg[0] == '#')
		return (0);
	i = 0;
	while (i <= REFRACTION_BLEND)
	{
		if (ft_strcmp(arg, data[i]) == 0)
			return (parse_elem(engine, mtl, save, i));
		++i;
	}
	return (0);
}

static int	parse_elem(t_engine *engine, t_obj_mtl *data, char *save, int i)
{
	static int	(*funcs[])(t_engine *engine, t_obj_mtl *data, char *line) = {
	[NEWMTL] = parse_newmtl,
	[KA] = NULL,
	[KD] = parse_kd,
	[KS] = parse_ks,
	[TF] = NULL,
	[ILLUM] = NULL,
	[DISSOLVE] = NULL,
	[NS] = parse_ns,
	[NI] = parse_ni,
	[MAP_BUMP] = parse_map_bump,
	[MAP_KD] = parse_map_kd,
	[REFLECTION] = parse_reflection,
	[REFRACTION] = parse_refraction,
	[REFRACTION_BLEND] = parse_refraction_blend
	};

	if (data->materials.size == 0 && i != NEWMTL)
		return (-1);
	if (funcs[i])
		return (funcs[i](engine, data, save));
	return (0);
}
