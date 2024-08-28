/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:50:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:39:42 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_string.h"
#include "object/material.h"
#include "object/optional_data.h"
#include "object/parse_util.h"

static int	fill_data(t_material_data *material, char *str);

int	parse_material(t_optional_data *data, char *arg)
{
	return (fill_data(&data->material, arg));
}

static int	fill_data(t_material_data *material, char *str)
{
	char	*save;
	char	*data;

	data = ft_strtok_r(str, ",", &save);
	if (parse_double(&material->diffuse_ratio, data, 0, 1) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->specular_ratio, data, 0, 1) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->specular_shine, data, 0, DBL_MAX) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->reflect_ratio, data, 0, 1) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->refraction_ratio, data, 0, 5) == -1)
		return (-1);
	if (material->refraction_ratio > 0 && material->refraction_ratio < 1)
		return (-1);
	return (0);
}
