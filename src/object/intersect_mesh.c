/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_mesh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:00:38 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/13 03:59:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "util.h"
#include "vector.h"

double	intersect_mesh(t_object *obj, t_ray *ray)
{
	size_t	i;
	double	t = -1;
	t_hit_data	data;

	i = 0;
	while (i < obj->data.mesh.obj_3d->faces.size)
	{
		t_polygon	*face = at_vector(&obj->data.mesh.obj_3d->faces, i);
		if (get_closest_distance_ptr(intersect_cached_triangle(&face->cache, ray), t, &t))
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
