/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_kd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:49:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 15:23:28 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int	parse_map_kd(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;
	char			*relative;

	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	material->texture = parse_texture_if_needed(engine, line);
	if (material->texture == NULL)
	{
		relative = get_relative_path(mtl->file_name, line);
		material->texture = parse_texture_if_needed(engine, relative);
		free(relative);
		if (material->texture == NULL)
			return (-1);
	}
	return (0);
}
