/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_space_vertices.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:23:53 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/22 16:24:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "ft_string.h"
#include "object/parse_util.h"
#include "obj_3d.h"

int	parse_obj_space_vertice(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec3	vec;
	char	*save;

	(void) engine;
	if (parse_double(&vec.x, ft_strtok_r(line, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_double(&vec.y, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.y = 0;
	if (parse_double(&vec.z, ft_strtok_r(NULL, " \t", &save), -DBL_MAX, DBL_MAX) == -1)
		vec.z = 0;
	if (add_vector(&obj->texture_coordinates, &vec, 1) == -1)
		return (-1);
	return (0);
}
