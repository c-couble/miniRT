/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_if_needed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:59:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/16 07:24:43 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "texture.h"

static t_texture	*add_new_texture(t_engine *engine, char *file);

t_texture	*parse_texture_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_texture	*current;

	i = 0;
	while (i < engine->textures.size)
	{
		current = at_vector(&engine->textures, i);
		if (ft_strcmp(file, current->file_name) == 0)
			return (current);
		++i;
	}
	return (add_new_texture(engine, file));
}

static t_texture	*add_new_texture(t_engine *engine, char *file)
{
	t_texture	*tx;

	tx = malloc(sizeof(t_texture));
	if (tx == NULL)
		return (NULL);
	ft_memset(tx, 0, sizeof(t_texture));
	if (parse_texture_file(tx, file) == -1)
	{
		free(tx);
		return (NULL);
	}
	if (add_vector(&engine->textures, &tx, 1) == -1)
	{
		clear_texture(tx);
		return (NULL);
	}
	return (tx);
}
