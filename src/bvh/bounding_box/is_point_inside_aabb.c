/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_point_inside_aabb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:28:36 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 23:32:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

int	is_point_iside_aabb(t_vec3 *point, t_aabb *aabb)
{
	if (point->x < aabb->min.x || point->x > aabb->max.x)
		return (0);
	if (point->y < aabb->min.y || point->y > aabb->max.y)
		return (0);
	if (point->z < aabb->min.z || point->z > aabb->max.z)
		return (0);
	return (1);
}
