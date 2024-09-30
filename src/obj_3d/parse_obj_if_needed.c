/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_if_needed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 04:27:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 20:34:49 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "engine.h"
#include "obj_3d.h"
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "engine.h"
#include "obj_3d.h"

static t_obj_3d	*add_new_obj(t_engine *engine, char *file);

t_obj_3d	*parse_obj_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_obj_3d	**current;

	i = 0;
	while (i < engine->objs_3d.size)
	{
		current = at_vector(&engine->objs_3d, i);
		if (ft_strcmp(file, (*current)->file_name) == 0)
			return (*current);
		++i;
	}
	return (add_new_obj(engine, file));
}

static t_obj_3d	*add_new_obj(t_engine *engine, char *file)
{
	t_obj_3d	*obj;

	obj = malloc(sizeof(t_obj_3d));
	if (obj == NULL)
		return (NULL);
	ft_memset(obj, 0, sizeof(t_obj_3d));
	if (parse_obj_file(engine, obj, file) == -1)
	{
		ft_dprintf(2, "Parsing error in %s\n", file);
		free(obj);
		return (NULL);
	}
	if (add_vector(&engine->objs_3d, &obj, 1) == -1)
	{
		clear_obj_3d(obj);
		free(obj);
		return (NULL);
	}
	return (obj);
}
