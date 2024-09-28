/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:55:11 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 09:31:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"

static int		search_for_mesh(t_bvh_node *n, t_object *objs);

int	init_bvh(t_bvh *bvh, t_vector *objs)
{
	bvh->bvh = init_bvh_tree(objs);
	if (bvh->bvh == NULL)
		return (-1);
	bvh->depth = 0;
	bvh->bvh_mode = NONE;
	get_bvh_depth(bvh->bvh, 0, &bvh->max_depth);
	bvh->max_depth += search_for_mesh(bvh->bvh, objs->array);
	return (0);
}

static int	search_for_mesh(t_bvh_node *n, t_object *objs)
{
	const int	size = n->start + n->size;
	int			i;
	int			deepest_depth;
	int			tmp;

	i = n->start;
	deepest_depth = 0;
	tmp = 0;
	while (i < size)
	{
		if (objs[i].type == MESH)
		{
			get_bvh_depth(objs[i].data.mesh.bvh, 0, &tmp);
			if (tmp > deepest_depth)
				deepest_depth = tmp;
		}
		++i;
	}
	return (deepest_depth);
}
