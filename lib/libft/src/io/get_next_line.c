/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/28 01:13:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_mem.h"
#include "vector.h"

static int		read_from_fd(int fd, t_buffer *buf, t_vector *line);
static int		add_str_to_line(t_vector *line, char *s, size_t n);
static char		*finish_line(t_vector *line);

char	*get_next_line(int fd)
{
	static t_buffer	buf = {{0}, 0, 0};
	t_vector		line;
	char			*nl;

	init_vector(&line, sizeof(char));
	nl = ft_memchr(buf.buf + buf.start, '\n', buf.end - buf.start);
	while (nl == NULL)
	{
		if (buf.end != buf.start && add_str_to_line(&line, buf.buf + \
					buf.start, buf.end - buf.start))
			return (NULL);
		if (read_from_fd(fd, &buf, &line))
			return (NULL);
		if (buf.end == 0)
			return (finish_line(&line));
		nl = ft_memchr(buf.buf + buf.start, '\n', buf.end - buf.start);
	}
	++nl;
	if (add_str_to_line(&line, buf.buf + buf.start, nl - (buf.buf + buf.start)))
		return (NULL);
	buf.start = nl - buf.buf;
	return (finish_line(&line));
}

static int	read_from_fd(int fd, t_buffer *buf, t_vector *line)
{
	buf->end = read(fd, buf->buf, BUFFER_SIZE);
	buf->start = 0;
	if (buf->end < 0)
	{
		if (line->array)
			free(line->array);
		buf->end = 0;
		return (1);
	}
	return (0);
}

static int	add_str_to_line(t_vector *line, char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (add_vector(line, s + i, 1))
			return (1);
		++i;
	}
	return (0);
}

static char	*finish_line(t_vector *line)
{
	char	*new;

	if (line->array == NULL)
		return (NULL);
	new = malloc(line->size + 1);
	if (new == NULL)
	{
		free(line->array);
		return (NULL);
	}
	ft_memcpy(new, line->array, line->size);
	new[line->size] = '\0';
	free(line->array);
	return (new);
}
