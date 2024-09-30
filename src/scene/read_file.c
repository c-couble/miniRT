/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:27:20 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 20:37:05 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine.h"
#include "ft_io.h"
#include "object.h"
#include "util.h"

static int	add_object(t_engine *engine, t_scene *scene, char *line, size_t i);
static int	add_created_object(t_scene *scene, t_object *obj);
static int	add_plane_and_object(t_scene *scene, t_object *obj);

int	read_file(t_engine *engine, t_scene *scene, int fd)
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
		ft_dprintf(STDERR_FILENO, "Error\nParsing error on line %d\n", (int) i);
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
	else if (add_plane_and_object(scene, obj) == -1)
	{
		print_error("Memory allocation failure");
		return (-1);
	}
	return (0);
}

static int	add_plane_and_object(t_scene *scene, t_object *obj)
{
	if (obj->type == PLANE)
	{
		if (add_vector(&scene->planes, obj, 1) == -1)
			return (-1);
	}
	else if (add_vector(&scene->objects, obj, 1) == -1)
		return (-1);
	return (0);
}
