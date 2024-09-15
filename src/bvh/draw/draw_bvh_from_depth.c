/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh_from_depth.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:28:46 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 15:47:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "defines.h"
#include "draw.h"

void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	if (is_leaf(bvh))
		return ;
	draw_bvh_from_depth(eng, bvh->left, depth + 1);
	draw_bvh_from_depth(eng, bvh->right, depth + 1);
	if (depth >= eng->scene.bvh_depth)
	{
		get_bounding_box(&bvh->aabb);
		draw_bounding_box(eng, &bvh->aabb.box,
			get_interpolate_color(BLUE, GREEN, depth, eng->scene.bvh_m_depth));
	}
}
