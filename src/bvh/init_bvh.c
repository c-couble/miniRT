/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:55:11 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 03:05:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include <stdio.h>

void	kaboul(t_vector *obj, int *bvh_depth);

int	init_bvh(t_bvh *bvh, t_vector *objs)
{
	bvh->bvh = init_bvh_tree(objs);
	if (bvh->bvh == NULL)
		return (-1);
	bvh->depth = 0;
	bvh->bvh_mode = NONE;
	get_bvh_depth(bvh->bvh, 0, &bvh->max_depth);
	kaboul(objs, &bvh->depth);
	return (0);
}

void	kaboul(t_vector *obj, int *bvh_depth)
{
	size_t		i;
	int			tmp;
	t_object 	*objs;

	i = 0;
	tmp = 0;
	objs = obj->array;
	while (i < obj->size)
	{
		if (objs[i].type == MESH)
			get_bvh_depth(objs[i].data.mesh.bvh, 0, &tmp);
		if (tmp > *bvh_depth)
			*bvh_depth = tmp;
		++i;
	}
}
