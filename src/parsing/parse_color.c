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

int	parse_color(t_color *color)
{
	char	*arg;
	char	*save;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	save = NULL;
	if (parse_uint8t(&color->rgb.r, ft_strtok_r(arg, ",", &save)) == -1)
		return (-1);
	if (parse_uint8t(&color->rgb.g, ft_strtok_r(NULL, ",", &save)) == -1)
		return (-1);
	if (parse_uint8t(&color->rgb.b, ft_strtok_r(NULL, ",", &save)) == -1)
		return (-1);
	return (0);
}
