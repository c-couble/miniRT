/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:33:54 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 19:33:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "bvh.h"
#include "mlx_wrapper.h"
#include "object.h"
#include "util.h"
#include "vec3.h"
#include "vector.h"
#include <stdio.h>

static void	swap_obj(t_object *a, t_object *b);
static int	split_objs(t_vector *src, t_vector *left, t_vector *right);
static int	subdivide(t_bvh_node *node, int depth, int *mem_depth);
static void	sort_axis(t_bvh_node *node, double split_pos, int axis);

t_bvh_node	*init_bvh(t_vector *objs, int depth, int *mem_depth)
{
	t_bvh_node	*node;
	t_object	*curr;
	size_t		i;

	node = create_bvh_node();
	if (node == NULL)
		return (NULL);
	*mem_depth = depth;
	i = 0;
	while (i < objs->size)
	{
		curr = at_vector(objs, i);
		printf("object type = %d\n", curr->type);
		if (add_vector(&node->objects, curr, 1) == -1)
			return (NULL);
		++i;
	}
	update_node_aabb(node);
	if (subdivide(node, depth, mem_depth) == -1)
		return (NULL);
	return (node);
}

static int	subdivide(t_bvh_node *node, int depth, int *mem_depth)
{
	t_vec3		split_plane;
	int			axis;
	double		split_pos;
	t_vector	left;
	t_vector	right;

	vec3_subtract(&node->aabb.max, &node->aabb.min, &split_plane);
	axis = X;
	if (split_plane.y > split_plane.x)
		axis = Y;
	if (split_plane.z > get_axis(&split_plane, axis))
		axis = Z;
	split_pos = get_axis(&node->aabb.min, axis)
		- get_axis(&split_plane, axis) + 0.5;
	sort_axis(node, split_pos, axis);
	init_vector(&left, sizeof(t_object));
	init_vector(&right, sizeof(t_object));
	if (split_objs(&node->objects, &left, &right) == -1)
		return (-1);
	if (left.size == 0 || right.size == 0)
		return (0);
	node->left = init_bvh(&left, depth + 1, mem_depth);
	if (node->left == NULL)
		return (-1);
	node->right = init_bvh(&right, depth + 1, mem_depth);
	if (node->right == NULL)
		return (-1);
	return (0);
}

static void	sort_axis(t_bvh_node *node, double split_pos, int axis)
{
	size_t		i;
	size_t		j;
	t_object	*obj;

	i = 0;
	j = node->objects.size - 1;
	while (i < j && node->objects.size > 1)
	{
		obj = at_vector(&node->objects, i);
		if (get_axis(&obj->aabb.min, axis) < split_pos)
			++i;
		else
		{
			swap_obj(obj, at_vector(&node->objects, j));
			--j;
		}
	}
}

static int	split_objs(t_vector *src, t_vector *left, t_vector *right)
{
	size_t				i;
	t_vector			*ptr;
	const size_t		half = src->size / 2;

	i = 0;
	while (i < src->size)
	{
		if (i < half)
			ptr = left;
		else
			ptr = right;
		if (add_vector(ptr, at_vector(src, i), 1) == -1)
			return (-1);
		++i;
	}
	return (0);
}

static void	swap_obj(t_object *a, t_object *b)
{
	t_object	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
