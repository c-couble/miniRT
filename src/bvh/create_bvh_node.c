/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bvh_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 18:53:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bvh.h"

t_bvh_node	*create_bvh_node(void)
{
	t_bvh_node	*node;

	node = malloc(sizeof(t_bvh_node));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	return (node);
}
