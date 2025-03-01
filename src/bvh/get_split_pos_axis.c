/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split_pos_axis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:37:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:52:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "defines.h"
#include "util.h"

double	get_split_pos_axis(t_bvh_node *node, int *axis)
{
	t_vec3	split_plane;
	double	split_pos;

	vec3_subtract(&node->aabb.max, &node->aabb.min, &split_plane);
	*axis = X;
	if (split_plane.y > split_plane.x)
		*axis = Y;
	if (split_plane.z > get_axis(&split_plane, *axis))
		*axis = Z;
	split_pos = get_axis(&node->aabb.min, *axis)
		+ get_axis(&split_plane, *axis) * 0.5;
	return (split_pos);
}
