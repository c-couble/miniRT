/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:55:11 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 21:11:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

int	init_bvh(t_bvh *bvh, t_vector *objs)
{
	bvh->bvh = init_bvh_tree(objs);
	if (bvh->bvh == NULL)
		return (-1);
	bvh->depth = 0;
	bvh->bvh_mode = NONE;
	bvh->max_depth = 0;
	get_bvh_depth(bvh->bvh, objs->array, 0, &bvh->max_depth);
	return (0);
}
