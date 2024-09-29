/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh_mesh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:32:46 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 05:30:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object/triangle.h"
#include "util.h"

static int	subdivide(t_bvh_node *node, t_cached_triangle *tri);
static int	get_left_len(t_bvh_node *n, t_cached_triangle *t, double p, int a);
static int	init_child_nodes(t_bvh_node *node, t_cached_triangle *tri, int ls);

t_bvh_node	*init_bvh_mesh(t_cached_triangle *tri, size_t size)
{
	t_bvh_node	*node;

	node = create_bvh_node();
	if (node == NULL)
		return (NULL);
	node->start = 0;
	node->size = size;
	update_node_aabb_mesh(node, tri);
	if (subdivide(node, tri) == -1)
	{
		clear_bvh_tree(node);
		return (NULL);
	}
	return (node);
}

static int	subdivide(t_bvh_node *node, t_cached_triangle *tri)
{
	int			axis;
	int			left_size;
	double		split_pos;

	split_pos = get_split_pos_axis(node, &axis);
	swap_tris(node, tri, split_pos, axis);
	left_size = get_left_len(node, tri, split_pos, axis);
	if (left_size == 0 || left_size == node->size)
		return (0);
	if (init_child_nodes(node, tri, left_size) == -1)
		return (-1);
	if (subdivide(node->left, tri) == -1)
		return (-1);
	if (subdivide(node->right, tri) == -1)
		return (-1);
	return (0);
}

static int	init_child_nodes(t_bvh_node *node, t_cached_triangle *tri, int ls)
{
	node->left = create_bvh_node();
	if (node->left == NULL)
		return (-1);
	node->right = create_bvh_node();
	if (node->right == NULL)
		return (-1);
	node->left->start = node->start;
	node->left->size = ls;
	node->right->start = node->start + ls;
	node->right->size = node->size - ls;
	update_node_aabb_mesh(node->left, tri);
	update_node_aabb_mesh(node->right, tri);
	node->size = 0;
	return (0);
}

static int	get_left_len(t_bvh_node *n, t_cached_triangle *t, double pos, int a)
{
	size_t		i;
	size_t		j;

	i = n->start;
	j = n->start + n->size;
	while (i < j)
	{
		if (get_axis(&t[i].aabb.center, a) < pos)
			++i;
		else
			return (i - n->start);
	}
	return (i - n->start);
}
