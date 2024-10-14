/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtllib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 15:29:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "float.h"
#include "engine.h"
#include "obj_3d.h"
#include "util.h"

int	parse_mtllib(t_engine *engine, t_obj_3d *obj, char *line)
{
	char	*relative;

	obj->mtl = parse_obj_mtl_if_needed(engine, line);
	if (obj->mtl == NULL)
	{
		relative = get_relative_path(obj->file_name, line);
		obj->mtl = parse_obj_mtl_if_needed(engine, relative);
		free(relative);
		if (obj->mtl == NULL)
			return (-1);
	}
	return (0);
}
