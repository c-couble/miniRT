/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:41:49 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 23:19:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "mlx_wrapper.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vector.h"
#include <stdio.h>

double		intersect_bvh(t_ray *ray, t_bvh_node *node, t_vector *objs)
{
	double		t;
	double		tmp;
	int			i;
	t_object	*obj;
	t_hit_data	data;

	t = -1;
	if (intersect_aabb(ray, &node->aabb) == -1)
		return (-1);
	if (node->size)
	{
		int size = node->size + node->start;
		i = node->start;
		while (i < (size))
		{
			obj = at_vector(objs, i);
			tmp = intersect(obj, ray);
			if (get_closest_distance_ptr(tmp, t, &t))
				data = ray->data;
			++i;
		}
		if (t != -1)
			ray->data = data;
		return (t);
	}
	t = intersect_bvh(ray, node->left, objs);
	if (t != -1)
		data = ray->data;
	tmp = intersect_bvh(ray, node->right, objs);
	if (get_closest_distance_ptr(tmp, t, &t))
		data = ray->data;
	if (t != -1)
		ray->data = data;
	return (t);
}
