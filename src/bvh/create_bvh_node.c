/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bvh_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 10:44:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bvh.h"
#include "object.h"
#include "vector.h"

t_bvh_node	*create_bvh_node(void)
{
	t_bvh_node	*node;

	node = malloc(sizeof(t_bvh_node));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	create_empty_aabb(&node->aabb);
	init_vector(&node->objects, sizeof(t_object));
	return (node);
}
