/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 17:28:04 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "vec3.h"

int	parse_light(t_engine *engine, t_object_data *data)
{
	(void) engine;
	if (parse_vector3d(&data->light.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&data->light.ratio, ft_strtok(NULL, " \t"), 0, 1) == -1)
		return (-1);
	data->light.color.rgb.r = 255;
	data->light.color.rgb.g = 255;
	data->light.color.rgb.b = 255;
	return (0);
}
