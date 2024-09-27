/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_objs_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 06:56:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 03:12:37 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_3d.h"
#include "vector.h"
#include <stdlib.h>

void	clear_objs_3d(t_vector *objs_3d)
{
	size_t		i;
	t_obj_3d	**obj;

	i = 0;
	while (i < objs_3d->size)
	{
		obj = at_vector(objs_3d, i);
		clear_obj_3d(*obj);
		free(*obj);
		++i;
	}
	clear_vector(objs_3d);
}
