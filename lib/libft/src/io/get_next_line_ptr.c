/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 05:13:44 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 05:16:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_mem.h"
#include "vector.h"

static int	read_lines(t_buffer *buf, t_vector *line, int fd);

char	*get_next_line_ptr(int fd, t_buffer *buf)
{
	t_vector		line;

	init_vector(&line, sizeof(char));
	if (read_lines(buf, &line, fd) == -1)
	{
		buf->end = 0;
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
