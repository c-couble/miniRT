/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:02:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 05:40:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "float.h"
#include "ft_mem.h"
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
	data->triangle.cached.material = NULL;
	ft_memset(&data->triangle.cached, 0, sizeof(t_vec3) * 3);
	data->triangle.cached.color = data->triangle.color;
	data->triangle.texture = NULL;
	vec3_subtract(&data->triangle.cached.points[1],
		&data->triangle.cached.points[0], &data->triangle.cached.e1);
	vec3_subtract(&data->triangle.cached.points[2],
		&data->triangle.cached.points[0], &data->triangle.cached.e2);
	vec3_cross(&data->triangle.cached.e1,
		&data->triangle.cached.e2, &data->triangle.cached.normal);
	vec3_normalize(&data->triangle.cached.normal);
	return (0);
}
