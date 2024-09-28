/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh_at_depth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:46:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 05:10:04 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "engine.h"
#include "object.h"
#include <stdio.h>

static void	draw_at_depth(t_engine *eng, t_bvh_node *bvh, int depth);
static void	draw_mesh_at_depth(t_engine *eng, t_object *objs, int depth);

void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox		bbox;

	if (bvh == NULL)
		return ;
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
	else if (bvh->size)
		draw_mesh_at_depth(eng, eng->scene.objects.array, depth);
}

static void	draw_mesh_at_depth(t_engine *eng, t_object *objs, int depth)
{
	size_t	i;

	i = 0;
	while (i < eng->scene.objects.size)
	{
		if (objs[i].type == MESH)
			draw_at_depth(eng, objs[i].data.mesh.bvh, depth);
		++i;
	}
}

static void	draw_at_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox	bbox;

	if (bvh == NULL)
		return ;
	if (depth < eng->scene.bvh.depth && bvh->size == 0)
	{
		draw_at_depth(eng, bvh->left, depth + 1);
		draw_at_depth(eng, bvh->right, depth + 1);
	}
	else if (depth == eng->scene.bvh.depth)
	{
		get_bbox_from_aabb(&bvh->aabb, &bbox);
		draw_bounding_box(eng, &bbox,
			get_depth_color(depth, eng->scene.bvh.max_depth));
	}
}
