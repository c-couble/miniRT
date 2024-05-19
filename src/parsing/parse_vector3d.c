/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:50:12 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 08:12:55 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object/parse_util.h"
#include "vector3d.h"
#include <stdio.h>

int	parse_vector3d(t_vector3d *vector, double min, double max)
{
	char	*arg;
	char	*save;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	save = NULL;
	if (parse_double(&vector->x, ft_strtok_r(arg, ",", &save), min, max) == -1)
		return (-1);
	if (parse_double(&vector->y, ft_strtok_r(NULL, ",", &save), min, max) == -1)
		return (-1);
	if (parse_double(&vector->z, ft_strtok_r(NULL, ",", &save), min, max) == -1)
		return (-1);
	return (0);
}
