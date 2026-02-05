/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_background_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 07:29:39 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:11:55 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"
#include "ft_string.h"
#include "object/parse_util.h"

static int		fill_data(t_colorf *bckg, char *str);
static float	normalize_uint8(uint8_t	in);

int	parse_background_color(t_engine *engine, t_option *data, char *arg)
{
	(void) data;
	return (fill_data(&engine->scene.background, arg));
}

static int	fill_data(t_colorf *bkg, char *str)
{
	char		*save;
	char		*data;
	uint8_t		tmp;

	data = ft_strtok_r(str, ",", &save);
	if (parse_uint8t(&tmp, data) == -1)
		return (-1);
	bkg->r = normalize_uint8(tmp);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_uint8t(&tmp, data) == -1)
		return (-1);
	bkg->g = normalize_uint8(tmp);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_uint8t(&tmp, data) == -1)
		return (-1);
	bkg->b = normalize_uint8(tmp);
	return (0);
}

static inline float	normalize_uint8(uint8_t	in)
{
	return ((float)in / 255.0);
}
