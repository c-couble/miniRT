/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_render_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 16:27:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "engine.h"
#include "vector.h"

static int	write_to_file(t_engine *engine, int fd);
static int	write_header(t_engine *engine, int fd);

int	save_render_file(t_engine *engine)
{
	int	fd;

	fd = open("render.ppm", O_CREAT | O_WRONLY, "0666");
	if (fd == -1)
		return (-1);
	if (write_to_file(engine, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	write_to_file(t_engine *engine, int fd)
{
	size_t		i;
	t_vector	v;
	int			ret;

	if (write_header(engine, fd) == -1)
		return (0);
	init_vector(&v, sizeof(uint8_t));
	i = 0;
	while (i < engine->render_size)
	{
		if (add_vector(&v, &engine->render_data[i].rgb, 3) == -1)
		{
			clear_vector(&v);
			return (-1);
		}
		++i;
	}
	ret = write(fd, v.array, v.size);
	clear_vector(&v);
	if (ret == -1)
		dprintf(2, "Error saving file\n");
	return (0);
}

static int	write_header(t_engine *engine, int fd)
{
	if (dprintf(fd, "P6\n%d\n%d\n255\n",
			engine->render_width, engine->render_height) == -1)
	{
		dprintf(2, "Error saving file\n");
		return (-1);
	}
	return (0);
}
