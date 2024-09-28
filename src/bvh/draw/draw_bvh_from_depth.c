/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh_from_depth.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:46:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 04:55:53 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "engine.h"
#include "object.h"

static void	draw_from_depth(t_engine *eng, t_bvh_node *bvh, int depth);

void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox		bbox;
	size_t		i;
	t_object	*objs;

	if (bvh == NULL)
		return ;
	if (bvh->size == 0)
	{
		draw_bvh_from_depth(eng, bvh->left, depth + 1);
		draw_bvh_from_depth(eng, bvh->right, depth + 1);
	}
	i = 0;
	objs = eng->scene.objects.array;
	while (i < eng->scene.objects.size)
	{
		if (objs[i].type == MESH)
			draw_from_depth(eng, objs[i].data.mesh.bvh, depth);
		++i;
	}
	if (depth >= eng->scene.bvh.depth)
	{
		get_bbox_from_aabb(&bvh->aabb, &bbox);
		draw_bounding_box(eng, &bbox,
			get_depth_color(depth, eng->scene.bvh.max_depth));
	}
}

static void	draw_from_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox	bbox;

	if (bvh == NULL)
		return ;
	if (bvh->size == 0)
	{
		draw_from_depth(eng, bvh->left, depth + 1);
		draw_from_depth(eng, bvh->right, depth + 1);
	}
	if (depth >= eng->scene.bvh.depth)
	{
		get_bbox_from_aabb(&bvh->aabb, &bbox);
		draw_bounding_box(eng, &bbox,
			get_depth_color(depth, eng->scene.bvh.max_depth));
	}
}
