/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:35:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 02:20:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ft_mem.h"
#include "ft_io.h"
#include "vector.h"
#include "object.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	init_scene(t_scene *scene, char *file)
{
	char		*line;
	int			fd;
	t_object	obj;
	size_t		i;

	ft_memset(scene, 0, sizeof(t_scene));
	init_vector(&scene->objects, sizeof(t_object));
	scene->scene_name = file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (init_object(&obj, line) == -1)
		{
			free(line);
			close(fd);
			dprintf(STDERR_FILENO, "Parsing error on line %ld\n", i);
			return (-1);
		}
		if (obj.type != COMMENT)
		{
			dprintf(2, "obj type=%d\n", obj.type);
		}
		free(line);
		line = get_next_line(fd);
		++i;
	}
	return (0);
}
