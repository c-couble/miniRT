/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_kd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:49:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/25 04:49:44 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "obj_mtl.h"
#include "object/material.h"

int	parse_map_kd(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;

	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	material->texture = parse_texture_if_needed(engine, line);
	if (material->texture == NULL)
		return (-1);
	return (0);
}
