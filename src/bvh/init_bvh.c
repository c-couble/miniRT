/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:33:54 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 12:39:57 by lespenel         ###   ########.fr       */
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
int	split_objs(t_vector *src, t_vector *left, t_vector *right);
int	subdivide(t_bvh_node *node, int depth);

t_bvh_node	*init_bvh(t_vector *objs, int depth)
{
	t_bvh_node	*node;

	printf("init bvh depth = %d\n", depth);
	node = create_bvh_node();
	if (node == NULL)
		return (NULL);
	size_t	i;
	i = 0;
//	print_objs(objs);
	while (i < objs->size)
	{
		t_object *curr = at_vector(objs, i);
		if (add_vector(&node->objects, curr, 1) == -1)
			return (NULL);
		++i;
	}
	printf("obj got copied to the node (%ld)\n", node->objects.size);
	printf("obj.size = %ld\n", objs->size);
	update_node_aabb(node);
	if (subdivide(node, depth) == -1)
		return (NULL);

	return (node);
}

int	subdivide(t_bvh_node *node, int depth)
{
	t_vec3	split_plane;
	int		axis;
	double	split_pos;

	printf("je rentre dans subdivie\n");
	vec3_subtract(&node->aabb.max, &node->aabb.min, &split_plane);
	axis = X;
	if (split_plane.y > split_plane.x)
		axis = Y;
	if (split_plane.z > get_axis(&split_plane, axis))
		axis = Z;
	split_pos = get_axis(&node->aabb.min, axis) - get_axis(&split_plane, axis) + 0.5;

	size_t	i;
	size_t	j;
	t_object *obj;
	i = 0;
	j = node->objects.size - 1;
	printf("node.obj.size = %ld\n", node->objects.size);
	printf("split pose = %lf\n", split_pos);
	while (i < j && node->objects.size > 1)
	{
		//printf("loop i: %ld j: %ld\n", i, j);
		obj = at_vector(&node->objects, i);
		if (get_axis(&obj->aabb.center, axis) < split_pos)
			++i;
		else
		{
			swap_obj(obj, at_vector(&node->objects, j));
			--j;
		}
	}
	printf("swaped objs (%ld)\n", node->objects.size);
	t_vector left;
	t_vector right;

	init_vector(&left, sizeof(t_object));
	init_vector(&right, sizeof(t_object));
	if (split_objs(&node->objects, &left, &right) == -1)
		return (-1);
	if (left.size == 0 || right.size == 0)
		return (0);
	node->left = init_bvh(&left, depth + 1);
	if (node->left == NULL)
		return (-1);
	node->right = init_bvh(&right, depth + 1);
	if (node->right == NULL)
		return (-1);
	return (0);
}

int	split_objs(t_vector *src, t_vector *left, t_vector *right)
{
	size_t				i;
	t_vector 			*ptr;
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
