/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/15 18:23:57 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "object/rgb.h"
#include "vector3d.h"
#include "float.h"

int	parse_sphere(t_object_data *data)
{
	char	*arg;

	if (parse_vector3d(&data->sphere.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->sphere.diameter, arg, 0, DBL_MAX) == -1)
		return (-1);
	if (parse_rgb(&data->sphere.color) == -1)
		return (-1);
	return (0);
}
