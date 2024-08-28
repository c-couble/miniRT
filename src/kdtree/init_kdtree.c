/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kdtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:31:40 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/28 03:51:41 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include "vector.h"

static int	split_photons(t_vector *photons, t_vector *left, t_vector *right);

t_kdtree	*init_kdtree(t_vector *photons, int depth)
{
	int			axis;
	t_photon	*median;
	t_vector	left;
	t_vector	right;
	t_kdtree	*node;

	if (photons->size == 0)
		return (NULL);
	axis = depth % 3;
	sort_photons_axis(photons, 0, photons->size - 1, axis);
	median = at_vector(photons, photons->size / 2);
	node = create_kdnode(median);
	if (node == NULL)
		return (NULL);
	if (split_photons(photons, &left, &right) == -1)
	{
		clear_vector(&left);
		clear_vector(&right);
		return (NULL);
	}
	node->left = init_kdtree(&left, depth + 1);
	node->right = init_kdtree(&right, depth + 1);
	clear_vector(&left);
	clear_vector(&right);
	return (node);
}

static int	split_photons(t_vector *photons, t_vector *left, t_vector *right)
{
	size_t		i;
	t_photon	*curr;

	init_vector(left, sizeof(t_photon));
	init_vector(right, sizeof(t_photon));
	i = 0;
	while (i < photons->size / 2)
	{
		curr = at_vector(photons, i);
		if (add_vector(left, curr, 1) == -1)
			return (-1);
		++i;
	}
	while (i < photons->size - 1)
	{
		curr = at_vector(photons, i);
		if (add_vector(right, curr, 1) == -1)
			return (-1);
		++i;
	}
	return (0);
}
