/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_mesh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:00:38 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 04:27:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "util.h"

double	intersect_mesh(t_object *obj, t_ray *ray)
{
	size_t				i;
	double				t;
	t_hit_data			data;
	t_cached_triangle	*cache;
	double				t2;

	t = -1;
	cache = obj->data.mesh.cache;
	i = 0;
	while (i < obj->data.mesh.triangles)
	{
		t2 = intersect_cached_triangle(cache + i, ray);
		if (get_closest_distance_ptr(t2, t, &t))
		{
			data = ray->data;
		}
		++i;
	}
	if (t == -1)
		return (-1);
	ray->data = data;
	return (t);
}
