/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_if_needed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:59:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/29 04:07:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_string.h"
#include "texture.h"

t_texture	*parse_texture_if_needed(t_engine *engine, char *file)
{
	size_t		i;
	t_texture	*current;
	t_texture	obj;

	i = 0;
	while (i < engine->objs_3d.size)
	{
		current = at_vector(&engine->objs_3d, i);
		if (ft_strcmp(file, current->file_name)	== 0)
			return (current);
		++i;
	}
	if (parse_texture_file(&obj, file) == -1)
		return (NULL);
	if (add_vector(&engine->objs_3d, &obj, 1) == -1)
		return (NULL);
	return (at_vector(&engine->objs_3d, engine->objs_3d.size - 1));
}
