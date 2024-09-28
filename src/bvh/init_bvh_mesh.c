/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh_mesh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:32:46 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 02:36:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object/triangle.h"
#include "util.h"
#include <stdio.h>

static int	subdivide(t_bvh_node *node, t_cached_triangle *tri);
static int	get_left_len(t_bvh_node *node, t_cached_triangle *tri, double pos,int axis);
static int	init_child_nodes(t_bvh_node *node, t_cached_triangle *tri, int left_size);

t_bvh_node	*init_bvh_mesh(t_cached_triangle *tri, size_t size)
{
	t_bvh_node	*node;

	node = create_bvh_node();
	if (node == NULL)
		return (NULL);
	node->start = 0;
	node->size = size;
	update_node_aabb_mesh(node, tri);
	print_node2(node, tri, "tri");
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
	swap_by_axis_mesh(node, tri, split_pos, axis);
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

static int	init_child_nodes(t_bvh_node *node, t_cached_triangle *tri, int left_size)
{
	node->left = create_bvh_node();
	if (node->left == NULL)
		return (-1);
	node->right = create_bvh_node();
	if (node->right == NULL)
		return (-1);
	node->left->start = node->start;
	node->left->size = left_size;
	node->right->start = node->start + left_size;
	node->right->size = node->size - left_size;
	update_node_aabb_mesh(node->left, tri);
	update_node_aabb_mesh(node->right, tri);
	node->size = 0;
	return (0);
}

static int	get_left_len(t_bvh_node *node, t_cached_triangle *tri, double pos, int axis)
{
	size_t		i;
	size_t		j;

	i = node->start;
	j = node->start + node->size;
	while (i < j)
	{
		if (get_axis(&tri[i].aabb.center, axis) < pos)
			++i;
		else
			return (i - node->start);
	}
	return (i - node->start);
}
