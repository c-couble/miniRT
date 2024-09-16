/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bvh_depth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:50:45 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 00:12:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

void	get_bvh_depth(t_bvh *bvh, int depth, int *depth_ptr)
{
	if (bvh->size)
		return ;
	*depth_ptr = depth;
	get_bvh_depth(bvh->left, depth + 1, depth_ptr);
	get_bvh_depth(bvh->right, depth + 1, depth_ptr);
}
