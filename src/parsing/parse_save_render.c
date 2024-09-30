/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_save_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:32:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 10:52:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "engine.h"
#include "object/parse_util.h"
#include <stdio.h>

int	parse_save_render(t_engine *engine, t_option *data, char *arg)
{
	char	*save;
	char	*str;

	printf("nique sa mere\n");
	(void) data;
	str = ft_strtok_r(arg, ",", &save);
	if (parse_int(&engine->render_width, str, 1, 100000) == -1)
		return (-1);
	str = ft_strtok_r(NULL, ",", &save);
	if (parse_int(&engine->render_height, str, 1, 100000) == -1)
		return (-1);
	return (0);
}
