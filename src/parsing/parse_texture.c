/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 06:42:56 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:44:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/optional_data.h"
#include <stdio.h>

int	parse_texture(t_engine *engine, t_option *data, char *arg)
{
	(void) engine;
	(void) data;
	printf("Got texture |%s|\n", arg);
	return (0);
}
