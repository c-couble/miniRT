/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:50:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 21:37:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "ft_string.h"
#include "object/material.h"
#include "object/optional_data.h"
#include "object/parse_util.h"
#include "float.h"
#include <stdio.h>
#include <stdlib.h>

static int	fill_data(t_material_data *material, char *str);

int	parse_material(t_engine *engine, t_option *data, char *arg)
{
	(void) engine;
	return (fill_data(&data->material, arg));
}

static int	fill_data(t_material_data *material, char *str)
{
	char	*save;
	char	*data;

	data = ft_strtok_r(str, ",", &save);
	if (parse_double(&material->diffuse_ratio, data, 0, 4) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->specular_ratio, data, 0, 5) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->specular_shine, data, 0, DBL_MAX) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->reflect_ratio, data, 0, 1) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->refract_index, data, 0, 5) == -1)
		return (-1);
	if (material->refract_index > 0 && material->refract_index < 1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (data == NULL)
		return (0);
	return ((parse_double(&material->refract_blend, data, 0, 1) == 0) - 1);
}
