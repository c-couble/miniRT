/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kdtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:31:40 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/30 02:05:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "kdtree.h"
#include "photon.h"
#include "vector.h"
#include "util.h"

static int	split_photons(t_vector *photons, t_vector *left, t_vector *right,
						 t_vec3 *median, int axis);

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
	remove_vector(photons, photons->size / 2);
	if (split_photons(photons, &left, &right, &node->photon.pos, axis) == -1)
	{
		clear_vector(&left);
		clear_vector(&right);
		free(node);
		return (NULL);
	}
	printf("\n\n");
	printf("init kdtree depth = %d, axis = %d\n", depth, axis);
	print_vec3(&node->photon.pos, "median = ");
	printf("left list = \n");
	print_photon_map(&left);
	printf("\n");
	printf("right list = \n");
	printf("\n");
	print_photon_map(&right);
	node->left = init_kdtree(&left, depth + 1);
	node->right = init_kdtree(&right, depth + 1);
	clear_vector(&left);
	clear_vector(&right);
	return (node);
}

static int	split_photons(t_vector *photons, t_vector *left, t_vector *right,
						 t_vec3 *median, int axis)
{
	size_t		i;
	t_photon	*curr;

	init_vector(left, sizeof(t_photon));
	init_vector(right, sizeof(t_photon));
	i = 0;
	printf("photons.size = %ld\n", photons->size);
	while (i < photons->size)
	{
		curr = at_vector(photons, i);
		printf("get axis curr->pos = %lf\n", get_axis(&curr->pos, axis));
		printf("get axis median = %lf\n", get_axis(median, axis));
		if (get_axis(&curr->pos, axis) < get_axis(median, axis))
		{
			if (add_vector(left, curr, 1) == -1)
				return (-1);
		}
		else
		{
			if (add_vector(right, curr, 1) == -1)
				return (-1);
		}
		++i;
	}
	return (0);
}
