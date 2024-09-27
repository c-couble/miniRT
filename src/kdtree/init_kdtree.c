/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kdtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:31:40 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 06:35:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "kdtree.h"
#include "vector.h"

static int	split_photons(t_vector *left, t_kdtree *node, int depth);
static int	fill_right(t_vector *left, t_vector *right);

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
	if (split_photons(photons, node, depth) == -1)
	{
		free(node);
		return (NULL);
	}
	return (node);
}

static int	split_photons(t_vector *left, t_kdtree *node, int depth)
{
	t_vector	right;

	init_vector(&right, sizeof(t_photon));
	if (fill_right(left, &right) == -1)
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

static int	fill_right(t_vector *left, t_vector *right)
{
	size_t		i;
	t_photon	*curr;

	i = left->size / 2;
	curr = at_vector(left, i);
	if (add_vector(right, curr, i) == -1)
	{
		clear_vector(right);
		return (-1);
	}
	remove_vector_from_end(left, i);
	return (0);
}
