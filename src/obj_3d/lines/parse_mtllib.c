/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_mtl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:32 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/25 05:07:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "engine.h"
#include "obj_3d.h"

int	parse_mtllib(t_engine *engine, t_obj_3d *obj, char *line)
{
	obj->mtl = parse_obj_mtl_if_needed(engine, line);
	if (obj->mtl == NULL)
		return (-1);
	return (0);
}
