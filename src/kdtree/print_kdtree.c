/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_kdtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/25 17:54:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include <stdio.h>

void	print_kdtree(t_kdtree *node, int depth)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < depth)
	{
		printf(" ");
		++i;
	}
	printf("( %lf, %lf, %lf )\n", node->photon.pos.x,
		node->photon.pos.y, node->photon.pos.z);
	print_kdtree(node->left, depth + 1);
	print_kdtree(node->right, depth + 1);
}
