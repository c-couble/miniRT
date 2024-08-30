/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kdtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:31:40 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/30 07:07:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "kdtree.h"

static int	split_photons(t_vector *left, t_kdtree *node, int depth, int axis);
static int	fill_right(t_vector *left, t_vector *right, t_kdtree *node, int ax);

t_kdtree	*init_kdtree(t_vector *photons, int depth)
{
	int			axis;
	t_photon	*median;
	t_kdtree	*node;

	if (photons->size == 0)
		return (NULL);
	axis = depth % 3;
	sort_photons_axis(photons, 0, photons->size - 1, axis);
	median = at_vector(photons, photons->size / 2);
	node = create_kdnode(median);
	if (node == NULL)
		return (NULL);
	remove_vector(photons, photons->size / 2);
	if (split_photons(photons, node, depth, axis) == -1)
	{
		free(node);
		return (NULL);
	}
	return (node);
}

static int	split_photons(t_vector *left, t_kdtree *node, int depth, int axis)
{
	t_vector	right;

	init_vector(&right, sizeof(t_photon));
	if (fill_right(left, &right, node, axis) == -1)
	{
		clear_vector(&right);
		return (-1);
	}
	node->left = init_kdtree(left, depth + 1);
	if (node->left == NULL && errno)
	{
		clear_vector(&right);
		return (-1);
	}
	node->right = init_kdtree(&right, depth + 1);
	if (node->right == NULL && errno)
	{
		clear_vector(&right);
		return (-1);
	}
	clear_vector(&right);
	return (0);
}

static int	fill_right(t_vector *left, t_vector *right, t_kdtree *node, int ax)
{
	size_t		i;
	t_photon	*curr;

	i = 0;
	while (i < left->size)
	{
		curr = at_vector(left, i);
		if (get_axis(&curr->pos, ax) > get_axis(&node->photon.pos, ax))
		{
			if (add_vector(right, curr, 1) == -1)
			{
				clear_vector(right);
				return (-1);
			}
			remove_vector(left, i);
		}
		else
			++i;
	}
	return (0);
}
