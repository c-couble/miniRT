/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:42:56 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/01 05:57:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "engine.h"
#include "ft_string.h"
#include "object/optional_data.h"
#include "texture.h"

int	parse_texture(t_engine *engine, t_option *data, char *arg)
{
	char	*save;
	char	*word;

	word = ft_strtok_r(arg, ",", &save);
	if (word == NULL)
		return (-1);
	data->texture = parse_texture_if_needed(engine, word);
	if (data->texture == NULL)
		return (-1);
	word = ft_strtok_r(NULL, ",", &save);
	if (word == NULL)
		return (0);
	data->up_texture = parse_texture_if_needed(engine, word);
	if (data->up_texture == NULL)
		return (-1);
	word = ft_strtok_r(NULL, ",", &save);
	if (word == NULL)
		return (0);
	data->down_texture = parse_texture_if_needed(engine, word);
	if (data->down_texture == NULL)
		return (-1);
	return (0);
}
