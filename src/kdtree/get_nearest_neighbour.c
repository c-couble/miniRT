/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_neighbour.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:32:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/29 04:39:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "float.h"
#include "kdtree.h"
#include "vec3.h"

static double	get_axis(t_vec3 *v, int axis);
static double	distance_squared(t_vec3 *a, t_vec3 *b);
static void		get_nearest(t_kdtree *node, t_query *best, t_vec3 *t, int d);
static void		set_best(t_kdtree *node, t_query *target, double dist);

t_kdtree	*get_nearest_neighbour(t_query *best, t_kdtree *tree, t_vec3 *aim)
{
	best->node = NULL;
	best->best_dist = DBL_MAX;
	get_nearest(tree, best, aim, 0);
	return (best->node);
}

static void	get_nearest(t_kdtree *node, t_query *best, t_vec3 *aim, int depth)
{
	int			axis;
	double		dist;
	t_kdtree	*next_branch;
	t_kdtree	*other_branch;
	double		dist_from_plane;

	if (node == NULL)
		return ;
	axis = depth % 3;
	dist = distance_squared(&node->photon.pos, aim);
	set_best(node, best, dist);
	if (get_axis(aim, axis) < get_axis(&node->photon.pos, axis))
	{
		next_branch = node->left;
		other_branch = node->right;
	}
	else
	{
		next_branch = node->right;
		other_branch = node->left;
	}
	get_nearest(next_branch, best, aim, depth + 1);
	dist_from_plane = get_axis(aim, axis) - get_axis(&node->photon.pos, axis);
	if (dist_from_plane * dist_from_plane < best->best_dist)
		get_nearest(other_branch, best, aim, depth + 1);
}

static double	distance_squared(t_vec3 *a, t_vec3 *b)
{
	return ((a->x - b->x) * (a->x - b->x)
		+ (a->y - b->y) * (a->y - b->y)
		+ (a->z - b->z) * (a->z - b->z));
}

static void	set_best(t_kdtree *node, t_query *best, double dist)
{
	if (dist < best->best_dist)
	{
		best->node = node;
		best->best_dist = dist;
	}
}

static double	get_axis(t_vec3 *v, int axis)
{
	if (axis == 0)
		return (v->x);
	if (axis == 1)
		return (v->y);
	return (v->z);
}
