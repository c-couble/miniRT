/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_leaf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:03:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 11:03:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

inline int	is_leaf(t_bvh_node *node)
{
	return (node->left == NULL && node->right == NULL);
}
