/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/30 03:33:50 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "get_next_line_utils.h"
#include "object/parse_util.h"
#include "texture.h"

static ssize_t	read_header(t_texture *texture, char *content);
static int		set_value(t_texture *texture, char *word);
static int		read_data(t_texture *texture, char *content);

int	parse_texture_file(t_texture *texture, char *file)
{
	int			fd;
	char		*content;
	t_buffer	*buf;
	ssize_t		offset;

	ft_memset(texture, 0, sizeof(t_texture));
	texture->file_name = file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	buf = malloc(sizeof(t_buffer));
	ft_memset(buf, 0, sizeof(t_buffer));
	content = get_next_line_ptr(fd, buf, "");
	free(buf);
	offset = read_header(texture, content);
	if (offset == -1)
		return (-1);
	return (read_data(texture, content + offset));
}

static ssize_t	kaboul(t_texture *texture, char *content, size_t i, size_t j)
{
	const char	tmp = content[i];
	int			result;

	content[i] = '\0';
	if (i != j)
	{
		result = set_value(texture, content + j);
		if (result == -1)
			return (-1);
		if (result == 1)
		{
			if (ft_strchr(" \t\r\n", content[i]) == NULL)
				return (-1);
			return (i + 1);
		}
	}
	content[i] = tmp;
	return (0);
}

static ssize_t	read_header(t_texture *texture, char *content)
{
	size_t	i;
	size_t	j;
	ssize_t	result;

	if (ft_strncmp(content, "P6", 2) != 0)
		return (-1);
	i = 2;
	while (content[i] && ft_strchr(" \t\r\n", content[i]))
		++i;
	while (content[i])
	{
		j = i;
		while (content[i] && ft_strchr(" \t\r\n", content[i]) == NULL && content[i] != '#')
			++i;
		result = kaboul(texture, content, i, j);
		if (result)
			return (result);
		if (content[i] == '#')
		{
			while (content[i] && content[i] != '\n')
				++i;
		}
		while (content[i] && ft_strchr(" \t\r\n", content[i]))
			++i;
	}
	return (0);
}

static int	set_value(t_texture *texture, char *word)
{
	int	result;
	int	tmp;

	if (texture->width == 0)
	{
		result = parse_int(&tmp, word, 1, INT_MAX);
		texture->width = tmp;
		return (result);
	}
	if (texture->height == 0)
	{
		result = parse_int(&tmp, word, 1, INT_MAX);
		texture->height = tmp;
		return (result);
	}
	if (parse_int(&texture->maxval, word, 255, 255) == -1)
		return (-1);
	return (1);
}

static int		read_data(t_texture *texture, char *content)
{
	size_t	i;
	t_color	*color;

	color = malloc((texture->width * texture->height) * sizeof(t_color));
	if (color == NULL)
		return (-1);
	texture->texture = color;
	i = 0;
	while (i < texture->width * texture->height)
	{
		ft_memcpy(&color[i].rgb.r, content + (i * 3), sizeof(uint8_t));
		ft_memcpy(&color[i].rgb.g, content + (i * 3) + 1, sizeof(uint8_t));
		ft_memcpy(&color[i].rgb.b, content + (i * 3) + 2, sizeof(uint8_t));
		++i;
	}
	return (0);
}
