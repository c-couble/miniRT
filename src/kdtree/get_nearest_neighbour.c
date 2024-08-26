/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_neighbour.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:32:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/26 20:42:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include <float.h>
#include <limits.h>

void	nearest_neighbour(t_kdtree *node, t_kaboul *kaboul, t_vec3 *target,
					   int depth);

double	distance_squared(t_vec3 *a, t_vec3 *b)
{
	double	ret;

	ret = (a->x - b->x) * (a->x - b->x) +
		(a->y - b->y) * (a->y - b->y) +
		(a->z - b->z) * (a->z - b->z);
	return (ret);
}

t_kdtree *get_nearest_neighbour(t_kdtree *tree, t_vec3 *target)
{
	t_kaboul kaboul;
	kaboul.node = NULL;
	kaboul.best_dist = DBL_MAX;
	nearest_neighbour(tree, &kaboul, target, 0);
	return (kaboul.node);
}

void	nearest_neighbour(t_kdtree *node, t_kaboul *kaboul, t_vec3 *target,
					   int depth)
{
	int			axis;
	double		dist;
	t_kdtree	*next_branch;

	if (node == NULL)
		return ;
	axis = depth % 3;
	dist = distance_squared(&node->photon.pos, target);
	if (dist < kaboul->best_dist)
	{
		kaboul->node = node;
		kaboul->best_dist = dist;
	}
	if ((axis == 0 && target->x < node->photon.pos.x) ||
	(axis == 1 && target->y < node->photon.pos.y) ||
	(axis == 2 && target->z < node->photon.pos.z))
	{
		next_branch = node->left;
	}
	else
	{
		next_branch = node->right;
	}
	nearest_neighbour(next_branch, kaboul, target, depth + 1);
}
