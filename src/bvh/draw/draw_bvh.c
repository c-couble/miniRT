/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:10:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 11:17:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "defines.h"
#include "draw.h"

void	draw_bvh(t_engine *eng, t_bvh_node *bvh, int depth)
{
	if (is_leaf(bvh))
		draw_bounding_boxes(eng, &bvh->objects, WHITE);
	else
	{
		draw_bvh(eng, bvh->left, depth + 1);
		draw_bvh(eng, bvh->right, depth + 1);
		get_bounding_box(&bvh->aabb);
		draw_bounding_box(eng, &bvh->aabb.box,
			get_interpolate_color(BLUE, GREEN, depth, eng->scene.bvh_m_depth));
	}
}
