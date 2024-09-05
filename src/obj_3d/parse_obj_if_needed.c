/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_if_needed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 04:27:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/05 04:42:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "obj_3d.h"
#include "ft_string.h"

t_obj_3d	*parse_obj_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_obj_3d	*current;
	t_obj_3d	*obj;

	i = 0;
	while (i < engine->objs_3d.size)
	{
		current = at_vector(&engine->objs_3d, i);
		if (ft_strcmp(file, current->file_name) == 0)
			return (current);
		++i;
	}
	obj = malloc(sizeof(t_obj_3d));
	if (obj == NULL)
		return (NULL);
	if (parse_obj_file(engine, obj, file) == -1)
	{
		free(obj);
		return (NULL);
	}
	if (add_vector(&engine->objs_3d, &obj, 1) == -1)
	{
		free(obj);
		return (NULL);
	}
	obj = *(t_obj_3d **)at_vector(&engine->objs_3d, engine->objs_3d.size - 1);
	return (obj);
}
