/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_background_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 07:29:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 09:24:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_string.h"
#include "object/parse_util.h"

static int	fill_data(t_color *bckg, char *str);

int	parse_background_color(t_engine *engine, t_option *data, char *arg)
{
	(void) engine;
	(void) data;
	return (fill_data(&engine->scene.background, arg));
}

static int	fill_data(t_color *background, char *str)
{
	char	*save;
	char	*data;

	data = ft_strtok_r(str, ",", &save);
	if (parse_uint8t(&background->rgb.r, data) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_uint8t(&background->rgb.g, data) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_uint8t(&background->rgb.b, data) == -1)
		return (-1);
	return (0);
}
