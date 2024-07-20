/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:50:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/20 02:23:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "ft_string.h"
#include "object/material.h"
#include "object/parse_util.h"
#include "float.h"
#include <stdlib.h>

static int	fill_data(t_material_data *material, char *str);

int	parse_material(t_material_data *material)
{
	char	*arg;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
	{
		material->diffuse_ratio = DIFFUSE_RATIO;
		material->specular_ratio = SPECULAR_RATIO;
		material->reflect_ratio = REFLECT_RATIO;
		material->refraction_ratio = REFRACTION_RATIO;
		material->specular_shine = SPECULAR_SHINE;
		return (0);
	}
	return (fill_data(material, arg));
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
	if (parse_double(&material->reflect_ratio, data, 0, 1) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->refraction_ratio, data, 1, 5) == -1)
		return (-1);
	data = ft_strtok_r(NULL, ",", &save);
	if (parse_double(&material->specular_shine, data, 0, DBL_MAX) == -1)
		return (-1);
	return (0);
}
