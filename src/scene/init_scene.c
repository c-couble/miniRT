/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:35:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/13 00:55:13 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ft_mem.h"
#include "ft_io.h"
#include "vector.h"
#include "object.h"
#include <fcntl.h>
#include <unistd.h>

int	init_scene(t_scene *scene, char *file)
{
	char		*line;
	int			fd;

	ft_memset(scene, 0, sizeof(t_scene));
	init_vector(&scene->objects, sizeof(t_object));
	scene->scene_name = file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
	}
	return (0);
}
