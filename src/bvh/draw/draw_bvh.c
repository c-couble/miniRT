/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:10:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/18 00:53:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "color.h"
#include "draw.h"

static void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth);
static void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth);

void	draw_bvh(t_engine *engine)
{
	if (engine->scene.camera.render_type == BOUNDING_BOX)
		draw_bounding_boxes(engine, &engine->scene.objects, WHITE);
	if (engine->scene.bvh.bvh_mode != NONE)
	{
		if (engine->scene.bvh.bvh_mode == FULL_LAYER)
			draw_bvh_from_depth(engine, engine->scene.bvh.bvh, 0);
		else
		{
				draw_bvh_at_depth(engine, engine->scene.bvh.bvh, 0);
		}
	}
}

static void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox	bbox;

	if (bvh->size == 0)
	{
		draw_bvh_from_depth(eng, bvh->left, depth + 1);
		draw_bvh_from_depth(eng, bvh->right, depth + 1);
	}
	if (depth >= eng->scene.bvh.depth)
	{
		get_bbox_from_aabb(&bvh->aabb, &bbox);
		draw_bounding_box(eng, &bbox,
			get_depth_color(depth, eng->scene.bvh.max_depth));
	}
}

static void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox	bbox;

	if (depth < eng->scene.bvh.depth && bvh->size == 0)
	{
		draw_bvh_at_depth(eng, bvh->left, depth + 1);
		draw_bvh_at_depth(eng, bvh->right, depth + 1);
	}
	else if (depth == eng->scene.bvh.depth)
	{
		get_bbox_from_aabb(&bvh->aabb, &bbox);
		draw_bounding_box(eng, &bbox,
			get_depth_color(depth, eng->scene.bvh.max_depth));
	}
}
