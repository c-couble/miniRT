/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_render_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 13:25:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "engine.h"
#include "vector.h"

int	save_render_file(t_engine *engine)
{
	int fd = open("render.ppm", O_CREAT | O_WRONLY, "0666");
	if (fd == -1)
		return (-1);
	dprintf(fd, "P6\n%d\n%d\n255\n", engine->render_width, engine->render_height);

	size_t	i;
	t_vector	v;
	init_vector(&v, sizeof(uint8_t));
	size_t	kaboul;
	kaboul = engine->render_width * engine->render_height;
	i = 0;
	while (i < kaboul)
	{
		add_vector(&v, &engine->render_data[i].rgb.r, 1);
		add_vector(&v, &engine->render_data[i].rgb.g, 1);
		add_vector(&v, &engine->render_data[i].rgb.b, 1);
		++i;
	}
	write(fd, v.array, v.size);
	close(fd);
	return (0);
}
