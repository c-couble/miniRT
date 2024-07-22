/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:00:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/22 05:13:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "vec3.h"
#include "float.h"
#include <stdio.h>

int	parse_mesh(t_object_data *data)
{
	char	*arg;

	if (parse_vector3d(&data->mesh.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	data->mesh.name = ft_strdup(arg);
	if (data->mesh.name == NULL)
		return (-2);
	return (0);
}
