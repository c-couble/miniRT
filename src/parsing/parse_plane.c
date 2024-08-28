/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:11:30 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "color.h"
#include "object.h"
#include "vec3.h"

int	parse_plane(t_engine *engine, t_object_data *data)
{
	(void) engine;
	if (parse_vector3d(&data->plane.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->plane.normal) == -1)
		return (-1);
	if (parse_color(&data->plane.color) == -1)
		return (-1);
	return (0);
}
