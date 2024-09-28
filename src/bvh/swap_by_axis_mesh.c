/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_by_axis_mesh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:00:20 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 05:29:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object/triangle.h"
#include "util.h"

static void	swap_tri(t_cached_triangle *a, t_cached_triangle *b);

void	swap_tris(t_bvh_node *n, t_cached_triangle *tri, double pos, int axis)
{
	int			i;
	int			j;

	i = n->start;
	j = n->start + n->size - 1;
	while (i <= j)
	{
		if (get_axis(&tri[i].aabb.center, axis) < pos)
			++i;
		else
		{
			swap_tri(tri + i, tri + j);
			--j;
		}
	}
}

static void	swap_tri(t_cached_triangle *a, t_cached_triangle *b)
{
	t_cached_triangle	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
