/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:41:49 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 00:14:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vector.h"

static inline	double	hit(t_bvh *node, t_object *objs, t_ray *ray, double t);

double	intersect_bvh(t_ray *ray, t_bvh *node, t_vector *objs)
{
	double		t;
	double		tmp;
	t_hit_data	data;

	t = -1;
	if (intersect_aabb(ray, &node->aabb) == -1)
		return (-1);
	if (node->size)
		return (hit(node, objs->array, ray, t));
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

static inline	double	hit(t_bvh *node, t_object *objs, t_ray *ray, double t)
{
	const int	size = node->size + node->start;
	int			i;
	double		tmp;
	t_hit_data	data;

	i = node->start;
	while (i < size)
	{
		tmp = intersect(&objs[i], ray);
		if (get_closest_distance_ptr(tmp, t, &t))
			data = ray->data;
		++i;
	}
	if (t != -1)
		ray->data = data;
	return (t);
}
