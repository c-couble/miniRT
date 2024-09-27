/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:44:20 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 03:12:20 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_mtl.h"
#include "object/material.h"
#include "vector.h"
#include <stdlib.h>

void	clear_mtl(t_obj_mtl *mtl)
{
	size_t			i;
	t_material_data	*material;

	free(mtl->file_name);
	i = 0;
	while (i < mtl->materials.size)
	{
		material = at_vector(&mtl->materials, i);
		free(material->name);
		++i;
	}
	clear_vector(&mtl->materials);
}
