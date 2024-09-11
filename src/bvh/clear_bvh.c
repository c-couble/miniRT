/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:55:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 18:56:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bvh.h"

void	clear_bvh(t_bvh_node *bvh)
{
	if (bvh == NULL)
		return ;
	clear_bvh(bvh->left);
	clear_bvh(bvh->right);
	free(bvh);
}
