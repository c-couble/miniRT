/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:01:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/29 06:36:19 by ccouble          ###   ########.fr       */
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

static int	read_header(t_texture *texture, char *content, char **save);
static int	set_value(t_texture *texture, char *word);
//static int	read_data(t_texture *texture, char *content);

int	parse_texture_file(t_texture *texture, char *file)
{
	int	fd;
	char	*content;
	char	*save;

	ft_memset(texture, 0, sizeof(t_texture));
	texture->file_name = file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	t_buffer *buf = malloc(sizeof(t_buffer));
	ft_memset(buf, 0, sizeof(t_buffer));
	content = get_next_line_ptr(fd, buf, "");
	free(buf);
	if (read_header(texture, content, &save) == -1)
		return (-1);
	texture->texture = malloc((texture->width * texture->height) * sizeof(t_color));

	char *word;
	word = ft_strtok_r(NULL, "", &save);
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

static int	read_header(t_texture *texture, char *content, char **save)
{
	char	*word;
	int		comment;
	int		result;

	word = ft_strtok_r(content, " \t\r\n", save);
	if (ft_strcmp(word, "P6") != 0)
		return (-1);
	comment = 0;
	word = ft_strtok_r(NULL, " \t\r\n", save);
	while (word)
	{
		if (word[0] == '#')
			comment = 1;
		if (comment)
		{
			if (ft_strchr(word, '\n'))
				comment = 0;
		}
		else
		{
			result = set_value(texture, word);
			if (result != 0)
				return (result);
		}
		word = ft_strtok_r(NULL, " \t\r\n", save);
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
