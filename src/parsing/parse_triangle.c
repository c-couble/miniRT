/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:02:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 05:03:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "float.h"
#include "object.h"
#include "vec3.h"

int	parse_triangle(t_engine *engine, t_object_data *data)
{
	(void) engine;
	if (parse_vector3d(&data->triangle.p0, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->triangle.p1, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&data->triangle.p2, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->triangle.color) == -1)
		return (-1);
	data->triangle.cached.points[0] = data->triangle.p0;
	data->triangle.cached.points[1] = data->triangle.p1;
	data->triangle.cached.points[2] = data->triangle.p2;
	return (0);
}
