/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:16:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"
#include "vec3.h"
#include "float.h"

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
