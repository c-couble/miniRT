/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bvh_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:55:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 16:54:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bvh.h"

void	clear_bvh_tree(t_bvh_node *bvh)
{
	if (bvh == NULL)
		return ;
	clear_bvh_tree(bvh->left);
	clear_bvh_tree(bvh->right);
	free(bvh);
}
