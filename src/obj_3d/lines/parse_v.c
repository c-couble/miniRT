/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:26:12 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 04:59:54 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "ft_string.h"
#include "object/parse_util.h"
#include "obj_3d.h"
#include "vec4.h"

int	parse_v(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec4	vec;
	char	*save;
	char	*arg;

	(void) engine;
	arg = ft_strtok_r(line, " \t", &save);
	if (parse_double(&vec.x, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok_r(NULL, " \t", &save);
	if (parse_double(&vec.z, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok_r(NULL, " \t", &save);
	if (parse_double(&vec.y, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok_r(NULL, " \t", &save);
	if (parse_double(&vec.w, arg, -DBL_MAX, DBL_MAX) == -1)
		vec.w = 1;
	if (add_vector(&obj->vertices, &vec, 1) == -1)
		return (-1);
	return (0);
}
