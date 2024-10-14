/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 07:23:36 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 17:59:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "util.h"

int	parse_map_bump(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;
	char			*relative;

	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	relative = get_relative_path(mtl->file_name, line);
	if (relative == NULL)
		return (-1);
	material->normal_map = parse_texture_if_needed(engine, relative);
	free(relative);
	if (material->normal_map == NULL)
	{
		material->normal_map = parse_texture_if_needed(engine, line);
		if (material->normal_map == NULL)
			return (-1);
	}
	return (0);
}
