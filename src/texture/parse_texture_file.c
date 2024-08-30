/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/30 02:32:53 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "get_next_line_utils.h"
#include "object/parse_util.h"
#include "texture.h"

static ssize_t	read_header(t_texture *texture, char *content);
static int		set_value(t_texture *texture, char *word);
//static int	read_data(t_texture *texture, char *content);

int	parse_texture_file(t_texture *texture, char *file)
{
	int	fd;
	char	*content;

	ft_memset(texture, 0, sizeof(t_texture));
	texture->file_name = file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	t_buffer *buf = malloc(sizeof(t_buffer));
	ft_memset(buf, 0, sizeof(t_buffer));
	content = get_next_line_ptr(fd, buf, "");
	free(buf);
	ssize_t	offset = read_header(texture, content);
	if (offset == -1)
		return (-1);
	texture->texture = malloc((texture->width * texture->height) * sizeof(t_color));

	char *word = content + offset;
	int	i;
	i = 0;
	while (i < texture->width * texture->height)
	{
		ft_memcpy(&texture->texture[i].rgb.r, word + (i * 3), sizeof(uint8_t));
		ft_memcpy(&texture->texture[i].rgb.g, word + (i * 3) + 1, sizeof(uint8_t));
		ft_memcpy(&texture->texture[i].rgb.b, word + (i * 3) + 2, sizeof(uint8_t));
		++i;
	}
	return (0);
}

static ssize_t	read_header(t_texture *texture, char *content)
{
	int		result;
	size_t	i;
	size_t	j;

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
		char	tmp = content[i];
		content[i] = '\0';
		result = set_value(texture, content + j);
		if (result == -1)
			return (-1);
		if (result == 1)
		{
			if (ft_strchr(" \t\r\n", content[i]) == NULL)
				return (-1);
			return (i + 1);
		}
		content[i] = tmp;
		if (content[i] == '#')
		{
			printf("pre comment %ld\n", i);
			while (content[i] && content[i] != '\n')
				++i;
			printf("comment %ld\n", i);
		}
		while (content[i] && ft_strchr(" \t\r\n", content[i]))
			++i;
	}
	return (0);
}

static int	set_value(t_texture *texture, char *word)
{
	if (texture->width == 0)
		return (parse_int(&texture->width, word, 1, INT_MAX));
	if (texture->height == 0)
		return (parse_int(&texture->height, word, 1, INT_MAX));
	if (parse_int(&texture->maxval, word, 255, 255) == -1)
		return (-1);
	return (1);
}
