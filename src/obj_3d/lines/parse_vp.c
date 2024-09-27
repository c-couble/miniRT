/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:23:53 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/26 06:29:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "ft_string.h"
#include "object/parse_util.h"
#include "obj_3d.h"

int	parse_vp(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_vec3	vec;
	char	*save;
	char	*arg;

	(void) engine;
	arg = ft_strtok_r(line, " \t", &save);
	if (parse_double(&vec.x, arg, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok_r(NULL, " \t", &save);
	if (parse_double(&vec.y, arg, -DBL_MAX, DBL_MAX) == -1)
		vec.y = 0;
	arg = ft_strtok_r(NULL, " \t", &save);
	if (parse_double(&vec.z, arg, -DBL_MAX, DBL_MAX) == -1)
		vec.z = 0;
	if (add_vector(&obj->space_vertices, &vec, 1) == -1)
		return (-1);
	return (0);
}
