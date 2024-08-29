/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:42:56 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/29 04:06:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "engine.h"
#include "object/optional_data.h"
#include "texture.h"

int	parse_texture(t_engine *engine, t_option *data, char *arg)
{
	(void) engine;
	(void) data;
	printf("Got texture |%s|\n", arg);
	data->texture = parse_texture_if_needed(engine, arg);
	if (data->texture == NULL)
		return (-1);
	return (0);
}
