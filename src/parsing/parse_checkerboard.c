/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checkerboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:53:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 10:48:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "engine.h"
#include "ft_string.h"
#include "object/optional_data.h"
#include "object/parse_util.h"

static int	fill_data(t_checkerboard *material, char *str);

int	parse_checkerboard(t_engine *engine, t_option *data, char *arg)
{
	(void) engine;
	return (fill_data(&data->checker, arg));
}

static int	fill_data(t_checkerboard *checker, char *str)
{
	char	*save;
	char	*data;

	data = ft_strtok_r(str, ",", &save);
	if (parse_int(&checker->x_size, data, 0, INT_MAX / 2) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_int(&checker->y_size, data, 0, INT_MAX / 2) == -1)
		return (-1);
	if (parse_color(&checker->x_color) == -1)
		return (-1);
	if (parse_color(&checker->y_color) == -1)
		return (-1);
	checker->x_size *= 2;
	checker->y_size *= 2;
	return (0);
}
