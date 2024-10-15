/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bvh_depth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:50:45 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 21:16:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"

static int		search_for_mesh(t_bvh_node *n, t_object *objs);
static void		get_mesh_depth(t_bvh_node *bvh, int depth, int *depth_ptr);

void	get_bvh_depth(t_bvh_node *bvh, t_object *objs, int depth, int *d_ptr)
{
	int	mesh_depth;

	if (bvh == NULL)
		return ;
	mesh_depth = search_for_mesh(bvh, objs) + depth;
	if (mesh_depth > *d_ptr)
		*d_ptr = mesh_depth;
	get_bvh_depth(bvh->left, objs, depth + 1, d_ptr);
	get_bvh_depth(bvh->right, objs, depth + 1, d_ptr);
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
			get_mesh_depth(objs[i].data.mesh.bvh, 0, &tmp);
			if (tmp > deepest_depth)
				deepest_depth = tmp;
		}
		++i;
	}
	return (deepest_depth);
}

static void	get_mesh_depth(t_bvh_node *bvh, int depth, int *depth_ptr)
{
	if (bvh == NULL)
		return ;
	if (depth > *depth_ptr)
		*depth_ptr = depth;
	get_mesh_depth(bvh->left, depth + 1, depth_ptr);
	get_mesh_depth(bvh->right, depth + 1, depth_ptr);
}
