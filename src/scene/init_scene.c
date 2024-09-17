/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:35:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/17 17:07:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bvh.h"
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "object.h"
#include "scene.h"
#include "util.h"
#include "vector.h"

static int	get_file(char *file);
static int	read_file(t_engine *engine, t_scene *scene, int fd);
static int	add_object(t_engine *engine, t_scene *scene, char *line, size_t i);
static int	add_created_object(t_scene *scene, t_object *obj);

int	init_scene(t_engine *engine, t_scene *scene, char *file)
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
	init_vector(&scene->lights, sizeof(t_light));
	init_vector(&scene->planes, sizeof(t_object));
	if (read_file(engine, scene, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (scene->ambient_light.ratio == -1 || scene->camera.fov == -1)
	{
		print_error("You need one camera and one ambient light");
		return (-1);
	}
	if (init_bvh(&scene->bvh, &scene->objects) == -1)
	{
		print_error("Failed to init BVH");
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

static int	read_file(t_engine *engine, t_scene *scene, int fd)
{
	char		*line;
	size_t		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (add_object(engine, scene, line, i) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
		++i;
	}
	if (errno)
	{
		print_error("Error reading file");
		return (-1);
	}
	return (0);
}

static int	add_object(t_engine *engine, t_scene *scene, char *line, size_t i)
{
	t_object	obj;

	if (init_object(engine, &obj, line) == -1)
	{
		dprintf(STDERR_FILENO, "Error\nParsing error on line %ld\n", i);
		return (-1);
	}
	if (obj.type == LIGHT)
	{
		if (add_vector(&scene->lights, &obj.data.light, 1) == -1)
		{
			print_error("Memory allocation failure");
			return (-1);
		}
	}
	else if (obj.type != COMMENT)
	{
		if (add_created_object(scene, &obj) == -1)
			return (-1);
		if (obj.type == CAMERA)
			scene->has_camera = 1;
		else if (obj.type == AMBIENT_LIGHT)
			scene->has_ambient_light = 1;
	}
	return (0);
}

static int	add_created_object(t_scene *scene, t_object *obj)
{
	if (obj->type == CAMERA)
	{
		if (scene->has_camera)
		{
			print_error("You can't have multiple cameras");
			return (-1);
		}
		scene->camera = obj->data.camera;
	}
	else if (obj->type == AMBIENT_LIGHT)
	{
		if (scene->has_ambient_light)
		{
			print_error("You can't have multiple ambient lights");
			return (-1);
		}
		scene->ambient_light = obj->data.ambient_light;
	}
	else if (obj->type == PLANE)
	{
		if (add_vector(&scene->planes, obj, 1) == -1)
		{
			print_error("Memory allocation failure");
			return (-1);
		}
	}
	else if (add_vector(&scene->objects, obj, 1) == -1)
	{
		print_error("Memory allocation failure");
		return (-1);
	}
	return (0);
}
