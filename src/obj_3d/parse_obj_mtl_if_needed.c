/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_mtl_if_needed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 05:19:58 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 05:43:05 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "engine.h"
#include "ft_string.h"
#include "obj_mtl.h"

t_obj_mtl	*parse_obj_mtl_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_obj_mtl	*current;
	t_obj_mtl	mtl;

	i = 0;
	while (i < engine->obj_mtls.size)
	{
		current = at_vector(&engine->obj_mtls, i);
		if (ft_strcmp(file, current->file_name) == 0)
			return (current);
		++i;
	}
	if (parse_mtl_file(engine, &mtl, file) == -1)
		return (NULL);
	if (add_vector(&engine->obj_mtls, &mtl, 1) == -1)
		return (NULL);
	return (at_vector(&engine->obj_mtls, engine->obj_mtls.size - 1));
}
