/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_if_needed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:59:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/05 04:42:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "ft_string.h"
#include "texture.h"

t_texture	*parse_texture_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_texture	*current;
	t_texture	*tx;

	i = 0;
	while (i < engine->textures.size)
	{
		current = at_vector(&engine->textures, i);
		if (ft_strcmp(file, current->file_name) == 0)
			return (current);
		++i;
	}
	tx = malloc(sizeof(t_texture));
	if (tx == NULL)
		return (NULL);
	if (parse_texture_file(tx, file) == -1)
		return (NULL);
	if (add_vector(&engine->textures, &tx, 1) == -1)
		return (NULL);
	tx = *(t_texture **)at_vector(&engine->textures, engine->textures.size - 1);
	return (tx);
}
