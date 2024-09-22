/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_use_mtl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:26:58 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/22 16:27:13 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "ft_string.h"
#include "obj_3d.h"

int	parse_use_mtl(t_engine *engine, t_obj_3d *obj, char *line)
{
	size_t			i;
	t_material_data	*material;

	(void) engine;
	if (obj->mtl == NULL)
		return (-1);
	i = 0;
	while (i < obj->mtl->materials.size)
	{
		material = at_vector(&obj->mtl->materials, i);
		if (ft_strcmp(material->name, line) == 0)
		{
			obj->current_material = material;
			return (0);
		}
		++i;
	}
	return (-1);
}
