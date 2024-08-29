/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 05:13:44 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/29 03:31:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_mem.h"
#include "get_next_line_utils.h"
#include "vector.h"

static int	read_lines(t_buffer *buf, t_vector *line, int fd, const char *set);
static char	*get_nearest_line_end(char *start, const char *set, size_t len);

char	*get_next_line_ptr(int fd, t_buffer *buf, const char *charset)
{
	t_vector		line;

	init_vector(&line, sizeof(char));
	if (read_lines(buf, &line, fd, charset) == -1)
	{
		buf->end = 0;
		clear_vector(&line);
		return (NULL);
	}
	return (line.array);
}

static int	read_lines(t_buffer *buf, t_vector *line, int fd, const char *set)
{
	char	*bufstart;
	char	*nl;

	bufstart = buf->buf + buf->start;
	nl = get_nearest_line_end(bufstart, set, buf->end - buf->start);
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
		nl = get_nearest_line_end(bufstart, set, buf->end);
	}
	++nl;
	if (add_vector(line, bufstart, nl - (buf->buf + buf->start) - 1))
		return (-1);
	buf->start = nl - buf->buf;
	return (0);
}

static char	*get_nearest_line_end(char *start, const char *set, size_t len)
{
	char	*cur;
	char	*best;
	size_t	i;

	i = 0;
	best = NULL;
	while (set[i])
	{
		cur = ft_memchr(start, set[i], len);
		if (best == NULL || cur < best)
			best = cur;
		++i;
	}
	return (best);
}
