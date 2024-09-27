/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_mtl_if_needed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 05:19:58 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 04:31:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "ft_string.h"
#include "ft_mem.h"
#include "obj_mtl.h"

static t_obj_mtl	*add_new_mtl(t_engine *engine, char *file);

t_obj_mtl	*parse_obj_mtl_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_obj_mtl	*current;

	i = 0;
	while (i < engine->obj_mtls.size)
	{
		current = at_vector(&engine->textures, i);
		if (ft_strcmp(file, current->file_name) == 0)
			return (current);
		++i;
	}
	return (add_new_mtl(engine, file));
}

static t_obj_mtl	*add_new_mtl(t_engine *engine, char *file)
{
	t_obj_mtl	*mtl;

	mtl = malloc(sizeof(t_obj_mtl));
	if (mtl == NULL)
		return (NULL);
	ft_memset(mtl, 0, sizeof(t_obj_mtl));
	if (parse_mtl_file(engine, mtl, file) == -1)
	{
		dprintf(2, "Parsing error in %s\n", file);
		free(mtl);
		return (NULL);
	}
	if (add_vector(&engine->obj_mtls, &mtl, 1) == -1)
	{
		clear_mtl(mtl);
		free(mtl);
		return (NULL);
	}
	return (mtl);
}
