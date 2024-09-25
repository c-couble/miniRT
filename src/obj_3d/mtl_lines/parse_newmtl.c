/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_newmtl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:58:36 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/25 05:41:23 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine.h"
#include "ft_string.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "util.h"

int	parse_newmtl(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	material;
	t_material_data	*at;
	size_t			i;

	(void) engine;
	i = 0;
	while (i < mtl->materials.size)
	{
		at = at_vector(&mtl->materials, i);
		if (ft_strcmp(at->name, line) == 0)
			return (-1);
		++i;
	}
	init_material(&material);
	material.name = ft_strdup(line);
	if (material.name == NULL)
		return (-1);
	if (add_vector(&mtl->materials, &material, 1) == -1)
	{
		free(material.name);
		return (-1);
	}
	return (0);
}
