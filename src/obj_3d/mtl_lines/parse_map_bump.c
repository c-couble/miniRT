/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 07:23:36 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 07:24:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "obj_mtl.h"
#include "object/material.h"

int	parse_map_bump(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;

	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	material->normal_map = parse_texture_if_needed(engine, line);
	if (material->normal_map == NULL)
		return (-1);
	return (0);
}
