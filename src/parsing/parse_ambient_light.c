/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/11 01:39:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_string.h"
#include "object.h"
#include "object/ambient_light.h"
#include "object/parse_util.h"

int	parse_ambient_light(struct s_engine *engine, union u_object_data *data)
{
	char			*arg;
	t_ambient_light	*ambiant;

	(void) engine;
	ambiant = &data->ambient_light;
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&ambiant->ratio, arg, 0, 1) == -1)
		return (-1);
	if (parse_color(&ambiant->color) == -1)
		return (-1);
	ambiant->color_times_ratio = color_scale(ambiant->color, ambiant->ratio);
	return (0);
}
