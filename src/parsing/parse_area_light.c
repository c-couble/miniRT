/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_area_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:39:12 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/06 00:47:08 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

#include "engine.h"
#include "ft_string.h"
#include "object/parse_util.h"

int	parse_area_light(t_engine *engine, t_object_data *data)
{
	t_area_light	*a_l;

	(void) engine;
	a_l = &data->area_light;
	if (parse_vector3d(&a_l->pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&a_l->axis_u, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_vector3d(&a_l->axis_v, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&a_l->size_u, ft_strtok(NULL, " \t"), 0, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&a_l->size_v, ft_strtok(NULL, " \t"), 0, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&a_l->power, ft_strtok(NULL, " \t"), 0, 1) == -1)
		return (-1);
	if (parse_color(&a_l->color) == -1)
		return (-1);
	return (0);
}
