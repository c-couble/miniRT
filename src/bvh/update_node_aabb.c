/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_aabb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:36:19 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 22:13:10 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bvh.h"
#include "ft_math.h"
#include "object.h"
#include "vec3.h"
#include "vector.h"

void	update_node_aabb(t_bvh_node *node)
{
	size_t		i;
	t_object	*obj;

	i = 0;
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &node->aabb.min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &node->aabb.max);
	while (i < node->objects.size)
	{
		obj = at_vector(&node->objects, i);
		node->aabb.min.x = ft_dmin(node->aabb.min.x, obj->aabb.min.x);
		node->aabb.min.y = ft_dmin(node->aabb.min.y, obj->aabb.min.y);
		node->aabb.min.z = ft_dmin(node->aabb.min.z, obj->aabb.min.z);
		node->aabb.max.x = ft_dmax(node->aabb.max.x, obj->aabb.max.x);
		node->aabb.max.y = ft_dmax(node->aabb.max.y, obj->aabb.max.y);
		node->aabb.max.z = ft_dmax(node->aabb.max.z, obj->aabb.max.z);
		++i;
	}
}