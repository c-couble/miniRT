/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh_at_depth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:54:58 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 11:17:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "color_util.h"
#include "defines.h"
#include "draw.h"

void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	printf("draw bvh depth = %d\n", depth);
	if (is_leaf(bvh))
		return ;
	if (depth < eng->scene.bvh_depth)
	{
		draw_bvh_at_depth(eng, bvh->left, depth + 1);
		draw_bvh_at_depth(eng, bvh->right, depth + 1);
	}
	else
	{
		get_bounding_box(&bvh->aabb);
		draw_bounding_box(eng, &bvh->aabb.box,
			get_interpolate_color(BLUE, GREEN, depth, eng->scene.bvh_m_depth));
	}
}
