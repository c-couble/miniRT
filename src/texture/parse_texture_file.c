/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:29 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/05 20:08:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "color.h"
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "object/parse_util.h"
#include "texture.h"

static ssize_t	read_header(t_texture *texture, char *content);
static ssize_t	set_word(t_texture *texture, char *content, size_t i, size_t j);
static int		set_value(t_texture *texture, char *word);
static int		read_data(t_texture *texture, t_file *file, ssize_t offset);

int	parse_texture_file(t_texture *texture, char *path)
{
	ssize_t		offset;
	t_file		file;

	if (get_file_content(&file, path) == -1)
		return (-1);
	if (ft_strncmp(file.content, "P6", 2) != 0)
	{
		free(file.content);
		return (-1);
	}
	offset = read_header(texture, file.content);
	if (offset == -1 || read_data(texture, &file, offset) == -1)
	{
		free(file.content);
		return (-1);
	}
	free(file.content);
	texture->file_name = ft_strdup(path);
	if (texture->file_name == NULL)
	{
		free(texture->texture);
		return (-1);
	}
	return (0);
}

static ssize_t	read_header(t_texture *texture, char *content)
{
	size_t	i;
	size_t	j;
	ssize_t	result;

	i = 2;
	while (content[i] && ft_strchr(" \t\r\n", content[i]))
		++i;
	while (content[i])
	{
		j = i;
		while (content[i] && ft_strchr(" \t\r\n", content[i]) == NULL
			&& content[i] != '#')
			++i;
		result = set_word(texture, content, i, j);
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

static ssize_t	set_word(t_texture *texture, char *content, size_t i, size_t j)
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
	if (parse_int(&texture->maxval, word, 1, 255) == -1)
		return (-1);
	return (1);
}

static int	read_data(t_texture *tx, t_file *file, ssize_t offset)
{
	size_t		i;
	char		*current;
	t_color		tmp;

	if (offset + 3 * tx->width * tx->height != file->length)
		return (-1);
	tx->texture = malloc((tx->width * tx->height) * sizeof(t_colorf));
	if (tx->texture == NULL)
		return (-1);
	tmp.color = 0;
	i = 0;
	while (i < tx->width * tx->height)
	{
		current = file->content + offset + i * 3;
		ft_memcpy(&tmp.rgb.r, current, sizeof(uint8_t));
		ft_memcpy(&tmp.rgb.g, current + 1, sizeof(uint8_t));
		ft_memcpy(&tmp.rgb.b, current + 2, sizeof(uint8_t));
		tmp.rgb.r *= 255 / tx->maxval;
		tmp.rgb.g *= 255 / tx->maxval;
		tmp.rgb.b *= 255 / tx->maxval;
		tx->texture[i] = color_normalize(tmp);
		++i;
	}
	return (0);
}
