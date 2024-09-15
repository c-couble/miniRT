/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:41:49 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 11:05:18 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "mlx_wrapper.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vector.h"
#include <stdio.h>

double		intersect_bvh(t_ray *ray, t_bvh_node *node)
{
	double		t;
	double		tmp;
	size_t		i;
	t_object	*obj;
	t_hit_data	data;

	t = -1;
	if (intersect_aabb(ray, &node->aabb) == -1)
		return (-1);
	if (is_leaf(node))
	{
		i = 0;
//		printf("is leaf obj size = %ld\n", node->objects.size);
		while (i < node->objects.size)
		{
			obj = at_vector(&node->objects, i);
			tmp = intersect(obj, ray);
			if (get_closest_distance_ptr(tmp, t, &t))
				data = ray->data;
			++i;
		}
		if (t != -1)
			ray->data = data;
		return (t);
	}
	t = intersect_bvh(ray, node->left);
	if (t != -1)
		data = ray->data;
	tmp = intersect_bvh(ray, node->right);
	if (tmp != -1)
	{
		if (get_closest_distance_ptr(tmp, t, &t))
			data = ray->data;
	}
	if (t != -1)
		ray->data = data;
	return (t);
}
