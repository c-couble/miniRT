/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 06:24:15 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/05 07:37:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "get_next_line_utils.h"
#include "vector.h"

static int	read_content(t_vector *vec, int fd);

int	get_file_content(t_file *file, const char *path)
{
	int			fd;
	t_vector	vec;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	init_vector(&vec, sizeof(char));
	if (read_content(&vec, fd) == -1)
	{
		close(fd);
		clear_vector(&vec);
		return (-1);
	}
	if (close(fd) == -1)
	{
		clear_vector(&vec);
		return (-1);
	}
	file->content = vec.array;
	file->length = vec.size;
	return (0);
}

static int	read_content(t_vector *vec, int fd)
{
	char	*buffer;
	ssize_t	ret;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		if (add_vector(vec, buffer, ret) == -1)
		{
			free(buffer);
			return (-1);
		}
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ret);
}
