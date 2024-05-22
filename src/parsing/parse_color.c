/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:50:20 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/22 03:14:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "color.h"
#include <stdint.h>
#include <stdio.h>

static int	parse_uint8(uint8_t *n, char *nptr);

int	parse_color(t_color *color)
{
	char	*arg;
	char	*save;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	save = NULL;
	if (parse_uint8(&color->rgb.r, ft_strtok_r(arg, ",", &save)) == -1)
		return (-1);
	if (parse_uint8(&color->rgb.g, ft_strtok_r(NULL, ",", &save)) == -1)
		return (-1);
	if (parse_uint8(&color->rgb.b, ft_strtok_r(NULL, ",", &save)) == -1)
		return (-1);
	return (0);
}

static int	parse_uint8(uint8_t *data, char *nptr)
{
	int		n;

	if (nptr == NULL)
		return (-1);
	if (ft_atoi_ptr(&n, nptr) == -1)
		return (-1);
	if (n < 0 || n > 255)
		return (-1);
	*data = n;
	return (0);
}
