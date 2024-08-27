/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_neighbour.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:32:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 20:06:43 by lespenel         ###   ########.fr       */
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

t_kdtree *get_nearest_neighbour(t_kaboul *kaboul, t_kdtree *tree, t_vec3 *target)
{
	kaboul->node = NULL;
	kaboul->best_dist = DBL_MAX;
	nearest_neighbour(tree, kaboul, target, 0);
	return (kaboul->node);
}

void	nearest_neighbour(t_kdtree *node, t_kaboul *kaboul, t_vec3 *target, int depth)
{
	int			axis;
	double		dist;
	t_kdtree	*next_branch;
	t_kdtree	*other_branch;
	double		axis_lenght;

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
		other_branch = node->right;
	}
	else
	{
		next_branch = node->right;
		other_branch = node->left;
	}
	nearest_neighbour(next_branch, kaboul, target, depth + 1);
	axis_lenght = 0.0f;
	if (axis == 0)
		axis_lenght = target->x - node->photon.pos.x;
	else if (axis == 1)
		axis_lenght = target->y - node->photon.pos.y;
	else 
		axis_lenght = target->z - node->photon.pos.z;
	if (axis_lenght * axis_lenght < kaboul->best_dist)
		nearest_neighbour(other_branch, kaboul, target, depth + 1);
}
