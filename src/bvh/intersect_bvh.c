/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:41:49 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 16:50:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vector.h"

static inline	double	hit(t_bvh_node *node, t_object *o, t_ray *r, double t);

double	intersect_bvh(t_ray *ray, t_bvh_node *node, t_vector *objs)
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

static inline	double	hit(t_bvh_node *bvh, t_object *objs, t_ray *r, double t)
{
	const int	size = bvh->size + bvh->start;
	int			i;
	double		tmp;
	t_hit_data	data;

	i = bvh->start;
	while (i < size)
	{
		tmp = intersect(&objs[i], r);
		if (get_closest_distance_ptr(tmp, t, &t))
			data = r->data;
		++i;
	}
	if (t != -1)
		r->data = data;
	return (t);
}
