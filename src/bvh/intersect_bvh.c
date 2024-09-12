/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:41:49 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 13:10:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "mlx_wrapper.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vector.h"
#include <stdio.h>

static void add_ray_data(t_ray *ray);
int	is_leaf(t_bvh_node *node)
{
	return (node->left == NULL && node->right == NULL);
}

double		intersect_bvh(t_ray *ray, t_bvh_node *node)
{
	size_t		i;
	double		t;
	t_object	*obj;
	double		tmp;
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
		{
			ray->data = data;
			add_ray_data(ray);
		}
		return (t);
	}
	else
	{
		t = intersect_bvh(ray, node->left);
		if (t != -1)
			data = ray->data;
		double t2 = intersect_bvh(ray, node->right);
		if (t2 != -1)
		{
			if (get_closest_distance_ptr(t2, t, &t))
			{
				data = ray->data;
			}
		}
		if (t != -1)
			ray->data = data;
}
	return (t);
}
static void add_ray_data(t_ray *ray)
{
    ray->data.raw_normal = ray->data.normal;
    if (vec3_dot(&ray->ray, &ray->data.normal) < 0)
        vec3_scale(&ray->data.normal, -1);
    if (ray->data.texture)
    {
        ray->data.color = get_texture_color(ray->data.texture,
                ray->data.u, ray->data.v);
    }
}
