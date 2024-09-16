/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:10:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 20:44:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "draw.h"

static void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth);
static void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth);

void	draw_bvh(t_engine *engine)
{
	if (engine->scene.camera.bvh_mode != NONE)
	{
		if (engine->scene.camera.bvh_mode == PERSISTENT)
		{
			draw_bvh_from_depth(engine, engine->scene.bvh, 0);
			if (engine->scene.bvh_depth != engine->scene.bvh_depth + 1)
				draw_bounding_boxes(engine, &engine->scene.objects, WHITE);
		}
		else
		{
			if (engine->scene.bvh_depth == engine->scene.bvh_m_depth)
				draw_bounding_boxes(engine, &engine->scene.objects, WHITE);
			else
				draw_bvh_at_depth(engine, engine->scene.bvh, 0);
		}
	}
}

static void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	if (bvh->size)
		return ;
	draw_bvh_from_depth(eng, bvh->left, depth + 1);
	draw_bvh_from_depth(eng, bvh->right, depth + 1);
	if (depth >= eng->scene.bvh_depth)
	{
		get_bounding_box(&bvh->aabb);
		draw_bounding_box(eng, &bvh->aabb.box,
			get_depth_color(depth, eng->scene.bvh_m_depth));
	}
}

static void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	if (bvh->size)
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
			get_depth_color(depth, eng->scene.bvh_m_depth));
	}
}
