/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh_at_depth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:46:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 12:57:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "engine.h"
#include "object.h"

static void	draw_mesh_at_depth(t_engine *e, t_bvh_node *n, t_object *o, int d);
static void	draw_at_depth(t_engine *eng, t_bvh_node *bvh, int depth);

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
		draw_mesh_at_depth(eng, bvh, eng->scene.objects.array, depth);
}

static void	draw_mesh_at_depth(t_engine *e, t_bvh_node *n, t_object *obj, int d)
{
	int			i;
	const int	size = n->start + n->size;

	i = n->start;
	while (i < size)
	{
		if (obj[i].type == MESH)
			draw_at_depth(e, obj[i].data.mesh.bvh, d);
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
