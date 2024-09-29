/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh_from_depth.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:46:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 09:12:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "engine.h"
#include "object.h"

static void	search_for_mesh(t_engine *e, t_bvh_node *n, t_object *objs, int d);
static void	draw_from_depth(t_engine *eng, t_bvh_node *bvh, int depth);

void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth)
{
	t_bbox		bbox;

	if (bvh == NULL)
		return ;
	if (bvh->size == 0)
	{
		draw_bvh_from_depth(eng, bvh->left, depth + 1);
		draw_bvh_from_depth(eng, bvh->right, depth + 1);
	}
	search_for_mesh(eng, bvh, eng->scene.objects.array, depth);
	if (depth >= eng->scene.bvh.depth)
	{
		get_bbox_from_aabb(&bvh->aabb, &bbox);
		draw_bounding_box(eng, &bbox,
			get_depth_color(depth, eng->scene.bvh.max_depth));
	}
}

static void	search_for_mesh(t_engine *e, t_bvh_node *n, t_object *objs, int d)
{
	int			i;
	const int	size = n->start + n->size;

	i = n->start;
	while (i < size)
	{
		if (objs[i].type == MESH)
			draw_from_depth(e, objs[i].data.mesh.bvh, d);
		++i;
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
