/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_kdnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:36:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/28 03:20:41 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include <stdlib.h>

t_kdtree	*create_kdnode(t_photon *photon)
{
	t_kdtree	*node;

	node = malloc(sizeof(t_kdtree));
	if (node == NULL)
		return (NULL);
	node->photon = *photon;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
