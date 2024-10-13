/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:54:43 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/13 03:21:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_string.h"
#include "obj_mtl.h"
#include "object/material.h"
#include "object/parse_util.h"

int	parse_reflection(t_engine *engine, t_obj_mtl *mtl, char *line)
{
	t_material_data	*material;
	char			*save;
	char			*word;

	(void) engine;
	material = at_vector(&mtl->materials, mtl->materials.size - 1);
	word = ft_strtok_r(line, " \t", &save);
	return (parse_double(&material->reflect_ratio, word, 0, 1));
}
