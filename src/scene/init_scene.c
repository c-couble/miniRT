/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:35:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 16:25:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "defines.h"
#include "engine.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "scene.h"
#include "util.h"

static int	get_file(char *file);
static void	set_scene(t_scene *scene, char *file);
static int	fill_objects(t_engine *engine, t_scene *scene, char *file);

int	init_scene(t_engine *engine, t_scene *scene, char *file)
{
	set_scene(scene, file);
	if (fill_objects(engine, scene, file) == -1)
		return (-1);
	if (scene->ambient_light.ratio == -1 || scene->camera.fov == -1)
	{
		clear_objects_vectors(scene);
		print_error("You need one camera and one ambient light");
		return (-1);
	}
	if (init_bvh(&scene->bvh, &scene->objects) == -1)
	{
		clear_objects_vectors(scene);
		return (-1);
	}
	if (init_caustic(scene, &scene->caustic) == -1)
	{
		clear_bvh(&scene->bvh);
		clear_objects_vectors(scene);
		return (-1);
	}
	return (0);
}

static void	set_scene(t_scene *scene, char *file)
{
	ft_memset(scene, 0, sizeof(t_scene));
	scene->camera.fov = -1;
	scene->ambient_light.ratio = -1;
	scene->scene_name = file;
	scene->background.color = DEFAULT_BACKGROUND;
}

static int	fill_objects(t_engine *engine, t_scene *scene, char *file)
{
	int	fd;

	fd = get_file(file);
	if (fd == -1)
		return (-1);
	init_object_vectors(scene);
	if (read_file(engine, scene, fd) == -1)
	{
		clear_objects_vectors(scene);
		close(fd);
		return (-1);
	}
	close(fd);
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
