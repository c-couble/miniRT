/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:35:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/15 19:41:35 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ft_mem.h"
#include "ft_io.h"
#include "vector.h"
#include "object.h"
#include "ft_string.h"
#include "util.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	get_file(char *file);
static int	read_file(t_scene *scene, int fd);
static int	add_object(t_scene *scene, char *line, size_t i);

int	init_scene(t_scene *scene, char *file)
{
	int			fd;

	ft_memset(scene, 0, sizeof(t_scene));
	scene->camera.fov = -1;
	scene->ambient_light.ratio = -1;
	scene->scene_name = file;
	fd = get_file(file);
	if (fd == -1)
		return (-1);
	init_vector(&scene->objects, sizeof(t_object));
	if (read_file(scene, fd) == -1)
	{
		clear_vector(&scene->objects);
		close(fd);
		return (-1);
	}
	close(fd);
	if (scene->ambient_light.ratio == -1 || scene->camera.fov == -1)
	{
		clear_vector(&scene->objects);
		return (-1);
	}
	return (0);
}

static int	get_file(char *file)
{
	const size_t	len = ft_strlen(file);

	if (len < 3)
	{
		print_error("File must end in .rt");
		return (-1);
	}
	if (ft_strncmp(file + (len - 3), ".rt", 3) != 0)
	{
		print_error("File must end in .rt");
		return (-1);
	}
	return (open(file, O_RDONLY));
}

static int	read_file(t_scene *scene, int fd)
{
	char		*line;
	size_t		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (add_object(scene, line, i) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
		++i;
	}
	if (errno)
		return (-1);
	return (0);
}

static int	add_object(t_scene *scene, char *line, size_t i)
{
	t_object	obj;

	if (init_object(&obj, line) == -1)
	{
		dprintf(STDERR_FILENO, "Parsing error on line %ld\n", i);
		return (-1);
	}
	if (obj.type != COMMENT)
	{
		if (obj.type == CAMERA)
		{
			if (scene->camera.fov != -1)
				return (-1);
			scene->camera = obj.data.camera;
		}
		if (obj.type == AMBIENT_LIGHT)
		{
			if (scene->ambient_light.ratio != -1)
				return (-1);
			scene->ambient_light = obj.data.ambient_light;
		}
		else if (add_vector(&scene->objects, &obj, 1) == -1)
			return (-1);
	}
	return (0);
}
