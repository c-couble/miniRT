/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:02:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/10 12:21:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "color.h"
#include "vector3d.h"
#include "float.h"
#include <stdio.h>

int	parse_triangle(t_object_data *data)
{
	if (parse_vector3d(&data->triangle.p0, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->triangle.p1, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->triangle.p2, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->triangle.color) == -1)
		return (-1);
	return (0);
}
