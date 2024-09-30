/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:35:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 10:57:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include "caustic.h"
#include "engine.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "object.h"
#include "util.h"

static int	get_file(char *file);
static void	init_object_vectors(t_scene *scene);

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
	init_object_vectors(scene);
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
	if (init_bvh(&scene->bvh, &scene->objects) == -1
		|| init_caustic(scene, &scene->caustic) == -1)
		return (-1);
	return (0);
}

static void	init_object_vectors(t_scene *scene)
{
	init_vector(&scene->objects, sizeof(t_object));
	init_vector(&scene->lights, sizeof(t_light));
	init_vector(&scene->planes, sizeof(t_object));
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
