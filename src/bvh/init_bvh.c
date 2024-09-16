/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:33:54 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 22:47:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "mlx_wrapper.h"
#include "object.h"
#include "util.h"
#include "vector.h"

static int	subdivide(t_bvh_node *node, t_vector *objs);
static int	get_left_len(t_bvh_node *node, t_vector *obj, double pos, int axis);
static int	init_child_nodes(t_bvh_node *node, t_vector *objs, int left_size);

t_bvh_node	*init_bvh(t_vector *objs)
{
	t_bvh_node	*node;

	node = create_bvh_node();
	if (node == NULL)
		return (NULL);
	node->start = 0;
	node->size = objs->size;
	update_node_aabb(node, objs);
	if (subdivide(node, objs) == -1)
		return (NULL);
	return (node);
}

static int	init_child_nodes(t_bvh_node *node, t_vector *objs, int left_size)
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
	update_node_aabb(node->left, objs);
	update_node_aabb(node->right, objs);
	node->size = 0;
	return (0);
}

static int	subdivide(t_bvh_node *node, t_vector *objs)
{
	int			axis;
	int			left_size;
	double		split_pos;

	split_pos = get_split_pos_axis(node, &axis);
	swap_by_axis(node, objs, split_pos, axis);
	left_size = get_left_len(node, objs, split_pos, axis);
	if (left_size == 0 || left_size == node->size)
		return (0);
	if (init_child_nodes(node, objs, left_size) == -1)
		return (-1);
	if (subdivide(node->left, objs) == -1)
		return (-1);
	if (subdivide(node->right, objs) == -1)
		return (-1);
	return (0);
}

static int	get_left_len(t_bvh_node *node, t_vector *obj, double pos, int axis)
{
	size_t		i;
	size_t		j;
	t_object	*curr;

	i = node->start;
	j = node->start + node->size;
	while (i < j)
	{
		curr = at_vector(obj, i);
		if (get_axis(&curr->aabb.center, axis) < pos)
			++i;
		else
			return (i - node->start);
	}
	return (i - node->start);
}
