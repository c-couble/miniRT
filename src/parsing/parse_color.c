/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:50:20 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 08:15:36 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_string.h"
#include "object/parse_util.h"

static inline float	normalize_uint8(uint8_t	in);

int	parse_color(t_colorf *color)
{
	char	*arg;
	char	*save;
	uint8_t	tmp;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	save = NULL;
	if (parse_uint8t(&tmp, ft_strtok_r(arg, ",", &save)) == -1)
		return (-1);
	color->r = normalize_uint8(tmp);
	if (parse_uint8t(&tmp, ft_strtok_r(NULL, ",", &save)) == -1)
		return (-1);
	color->g = normalize_uint8(tmp);
	if (parse_uint8t(&tmp, ft_strtok_r(NULL, ",", &save)) == -1)
		return (-1);
	color->b = normalize_uint8(tmp);
	return (0);
}

static inline float	normalize_uint8(uint8_t	in)
{
	return ((float)in / 255.0);
}
