/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_kd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:55:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 12:04:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <defines.h>
#include "engine.h"
#include "ft_string.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "object/parse_util.h"

int	parse_kd(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;
	char			*save;
	double			r;
	double			g;
	double			b;

	(void) engine;
	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	if (parse_double(&r, ft_strtok_r(line, " \t", &save), 0, 1) == -1)
		return (-1);
	if (parse_double(&g, ft_strtok_r(NULL, " \t", &save), 0, 1) == -1)
		return (-1);
	if (parse_double(&b, ft_strtok_r(NULL, " \t", &save), 0, 1) == -1)
		return (-1);
	material->color.rgb.r = 255 * r;
	material->color.rgb.g = 255 * g;
	material->color.rgb.b = 255 * b;
	material->diffuse_ratio = MESH_DIFFUSE_RATIO;
	return (0);
}
