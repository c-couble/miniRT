/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 01:33:43 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 06:35:50 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "get_next_line_utils.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "object/parse_util.h"
#include "texture.h"
#include "util.h"
#include "vector.h"

static int	parse_line(t_engine *engine, t_obj_mtl *mtl, char *line);
static int	parse_newmtl(t_engine *engine, t_obj_mtl *mtl, char *line);
static int	parse_kd(t_engine *engine, t_obj_mtl *mtl, char *line);
static int	parse_map_kd(t_engine *engine, t_obj_mtl *mtl, char *line);

int	parse_mtl_file(t_engine *engine, t_obj_mtl *mtl, char *file)
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
	line = get_next_line_ptr(fd, buf, "\n");
	while (line)
	{
		if (parse_line(engine, mtl, line) == -1)
		{
			close(fd);
			return (-1);
		}
		line = get_next_line_ptr(fd, buf, "\n");
	}
	free(line);
	if (errno)
	{
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	printf("success mtl\n");
	return (0);
}

static int	parse_line(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	static int	(*funcs[])(t_engine *engine, t_obj_mtl *data, char *line) = {
	[NEWMTL] = parse_newmtl,
	[KA] = NULL,
	[KD] = parse_kd,
	[KS] = NULL,
	[TF] = NULL,
	[ILLUM] = NULL,
	[DISSOLVE] = NULL,
	[NS] = NULL,
	[NI] = NULL,
	[MAP_KD] = parse_map_kd
	};
	static char	*data[] = {
	[NEWMTL] = "newmtl",
	[KA] = "Ka",
	[KD] = "Kd",
	[KS] = "Ks",
	[TF] = "Tf",
	[ILLUM] = "illum",
	[DISSOLVE] = "d",
	[NS] = "Ns",
	[NI] = "Ni",
	[MAP_KD] = "map_Kd"
	};
	char	*arg;
	char	*save;

	arg = ft_strtok_r(line, " \t", &save);
	if (arg == NULL || arg[0] == '#')
		return (0);
	int i = 0;
	while (i <= MAP_KD)
	{
		if (ft_strcmp(arg, data[i]) == 0)
		{
			if (mtl->materials.size == 0 && i != NEWMTL)
				return (-1);
			if (funcs[i])
				return (funcs[i](engine, mtl, save));
		}
		++i;
	}
	return (0);
}

static int	parse_newmtl(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	material;
	t_material_data	*at;
	size_t			i;

	(void) engine;
	i = 0;
	while (i < mtl->materials.size)
	{
		at = at_vector(&mtl->materials, i);
		if (ft_strcmp(at->name, line) == 0)
			return (-1);
	}
	init_material(&material);
	material.name = ft_strdup(line);
	if (material.name == NULL)
		return (-1);
	printf("newmtl %s\n", material.name);
	if (add_vector(&mtl->materials, &material, 1) == -1)
	{
		free(material.name);
		return (-1);
	}
	return (0);
}

static int	parse_kd(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;
	char			*save;
	char			*word;

	(void) engine;
	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	word = ft_strtok_r(line, " \t", &save);
	return (parse_double(&material->diffuse_ratio, word, 0, 1));
}

static int	parse_map_kd(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;

	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	printf("try texture %s\n", line);
	material->texture = parse_texture_if_needed(engine, line);
	if (material->texture == NULL)
		return (-1);
	printf("got texture\n");
	return (0);
}
