/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_aabb_mesh.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:35:13 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 01:37:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "float.h"
#include "ft_math.h"
#include "bvh.h"
#include "object/triangle.h"

void	update_node_aabb_mesh(t_bvh_node *node, t_cached_triangle *tris)
{
	int			i;
	const int	size = node->start + node->size;

	i = node->start;
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &node->aabb.min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &node->aabb.max);
	while (i < size)
	{
		node->aabb.min.x = ft_dmin(node->aabb.min.x, tris[i].aabb.min.x);
		node->aabb.min.y = ft_dmin(node->aabb.min.y, tris[i].aabb.min.y);
		node->aabb.min.z = ft_dmin(node->aabb.min.z, tris[i].aabb.min.z);
		node->aabb.max.x = ft_dmax(node->aabb.max.x, tris[i].aabb.max.x);
		node->aabb.max.y = ft_dmax(node->aabb.max.y, tris[i].aabb.max.y);
		node->aabb.max.z = ft_dmax(node->aabb.max.z, tris[i].aabb.max.z);
		++i;
	}
}
