/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_knearest_neighbour.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:32:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 21:54:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "float.h"
#include "kdtree.h"
#include "util.h"
#include "vec3.h"
#include "vector.h"

static double	distance_squared(t_vec3 *a, t_vec3 *b);
static void		get_nearest(t_kdtree *node, t_knn *knn, t_vec3 *t, int d);
static void		set_best(t_kdtree *node, t_knn *knn, double dist);

void	get_knearest_neighbour(t_knn *knn, t_kdtree *tree, t_vec3 *aim)
{
	get_nearest(tree, knn, aim, 0);
}

static void	get_nearest(t_kdtree *node, t_knn *knn, t_vec3 *aim, int depth)
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
	set_best(node, knn, dist);
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
	get_nearest(next_branch, knn, aim, depth + 1);
	dist_from_plane = get_axis(aim, axis) - get_axis(&node->photon.pos, axis);
	if (dist_from_plane * dist_from_plane < knn->querys[knn->farest_idx].dist)
		get_nearest(other_branch, knn, aim, depth + 1);
}

static double	distance_squared(t_vec3 *a, t_vec3 *b)
{
	return ((a->x - b->x) * (a->x - b->x)
		+ (a->y - b->y) * (a->y - b->y)
		+ (a->z - b->z) * (a->z - b->z));
}

static void	set_best(t_kdtree *node, t_knn *knn, double dist)
{
	size_t	i;

	if (knn->nn_count < knn->nn_size)
	{
		knn->querys[knn->nn_count].node = node;
		knn->querys[knn->nn_count].dist = dist;
		if (dist > knn->farest_idx)
			knn->farest_idx = knn->nn_count;
		knn->nn_count += 1;
	}
	else
	{
		i = 0;
		while (i < knn->nn_count)
		{
			if (knn->querys[i].dist > knn->querys[knn->farest_idx].dist)
				knn->farest_idx = i;
			++i;
		}
		if (dist < knn->querys[knn->farest_idx].dist)
		{
			knn->querys[knn->farest_idx].node = node;
			knn->querys[knn->farest_idx].dist = dist;
		}
	}
}
