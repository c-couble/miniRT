/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:28:24 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_mem.h"
#include "get_next_line_utils.h"
#include "vector.h"

static int	read_lines(t_buffer *buf, t_vector *line, int fd);

char	*get_next_line(int fd)
{
	static t_buffer	buf = {{0}, 0, 0};
	t_vector		line;

	init_vector(&line, sizeof(char));
	if (read_lines(&buf, &line, fd) == -1)
	{
		buf.end = 0;
		clear_vector(&line);
		return (NULL);
	}
	return (line.array);
}

static int	read_lines(t_buffer *buf, t_vector *line, int fd)
{
	char	*bufstart;
	char	*nl;

	bufstart = buf->buf + buf->start;
	nl = ft_memchr(bufstart, '\n', buf->end - buf->start);
	while (nl == NULL)
	{
		if (buf->end != buf->start)
		{
			if (add_vector(line, bufstart, buf->end - buf->start) == -1)
				return (-1);
		}
		buf->end = read(fd, buf->buf, BUFFER_SIZE);
		buf->start = 0;
		if (buf->end == -1 || buf->end == 0)
			return (buf->end);
		bufstart = buf->buf;
		nl = ft_memchr(bufstart, '\n', buf->end);
	}
	++nl;
	if (add_vector(line, bufstart, nl - (buf->buf + buf->start) - 1))
		return (-1);
	buf->start = nl - buf->buf;
	return (0);
}
