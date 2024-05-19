/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/15 18:23:08 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "object/rgb.h"
#include "vector3d.h"
#include "float.h"

int	parse_plane(t_object_data *data)
{
	if (parse_vector3d(&data->plane.coordinates, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->plane.orientation) == -1)
		return (-1);
	if (parse_rgb(&data->plane.color) == -1)
		return (-1);
	return (0);
}
