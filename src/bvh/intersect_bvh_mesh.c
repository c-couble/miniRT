/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh_mesh.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:22:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 02:40:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include <stdio.h>

static inline	double	hit(t_bvh_node *bvh, t_cached_triangle *tris, t_ray *r, double t);

double	intersect_bvh_mesh(t_ray *ray, t_bvh_node *node, t_cached_triangle *tris)
{
	double		t;
	double		tmp;
	t_hit_data	data;

	t = -1;
	if (node == NULL || intersect_aabb(ray, &node->aabb) == -1)
		return (-1);
	if (node->size)
		return (hit(node, tris, ray, t));
	t = intersect_bvh_mesh(ray, node->left, tris);
	if (t != -1)
		data = ray->data;
	tmp = intersect_bvh_mesh(ray, node->right, tris);
	if (get_closest_distance_ptr(tmp, t, &t))
		data = ray->data;
	if (t != -1)
		ray->data = data;
	return (t);
}

static inline	double	hit(t_bvh_node *bvh, t_cached_triangle *tris, t_ray *r, double t)
{
	const int	size = bvh->size + bvh->start;
	int			i;
	double		tmp;
	t_hit_data	data;

	i = bvh->start;
	while (i < size)
	{
		//printf("oui\n");
		tmp = intersect_cached_triangle(tris + i, r);
		if (tmp > 0 && get_closest_distance_ptr(tmp, t, &t))
		{
			data = r->data;
		}
		++i;
	}
	if (t != -1)
		r->data = data;
	return (t);
}
