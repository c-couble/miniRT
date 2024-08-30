/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kdtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:31:40 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/30 06:48:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "kdtree.h"
#include "photon.h"
#include "vector.h"

static int	split_photons(t_vector *photons, t_kdtree *node, int depth, int axis);

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

int	fill_vectors(t_vector *photons, t_vector *left, t_vector *right, t_kdtree *node,
				 int axis)
{
	size_t		i;
	t_photon	*curr;
	t_vector	*ptr;

	i = 0;
	while (i < photons->size)
	{
		curr = at_vector(photons, i);
		if (get_axis(&curr->pos, axis) < get_axis(&node->photon.pos, axis))
			ptr = left;
		else
			ptr = right;
		if (add_vector(ptr, curr, 1) == -1)
		{
			clear_vector(left);
			clear_vector(right);
			return (-1);
		}
		++i;
	}
	return (0);
}

static int	split_photons(t_vector *photons, t_kdtree *node, int depth, int axis)
{
	t_vector	left;
	t_vector	right;

	init_vector(&left, sizeof(t_photon));
	init_vector(&right, sizeof(t_photon));
	if (fill_vectors(photons, &left, &right, node, axis) == -1)
		return (-1);
	node->left = init_kdtree(&left, depth + 1);
	if (node->left == NULL && errno)
	{
		clear_vector(&left);
		clear_vector(&right);
		return (-1);
	}
	node->right = init_kdtree(&right, depth + 1);
	if (node->right == NULL && errno)
	{
		clear_vector(&left);
		clear_vector(&right);
		return (-1);
	}
	clear_vector(&left);
	clear_vector(&right);
	return (0);
}
