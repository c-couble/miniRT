/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:55:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 11:08:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bvh.h"
#include "vector.h"

void	clear_bvh(t_bvh_node *bvh)
{
	if (bvh == NULL)
		return ;
	clear_bvh(bvh->left);
	clear_bvh(bvh->right);
	clear_vector(&bvh->objects);
	free(bvh);
}
