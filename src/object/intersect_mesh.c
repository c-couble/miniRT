/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_mesh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:00:38 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/25 05:58:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_3d.h"
#include "object.h"
#include "object/triangle.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"
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
		t_triangle	triangle;
		t_vec3	*vec;
		vec = at_vector(&obj->data.mesh.obj_3d->vertices, face->points[0].vertice_id - 1);
		triangle.p0 = *vec;
		vec = at_vector(&obj->data.mesh.obj_3d->vertices, face->points[1].vertice_id - 1);
		triangle.p1 = *vec;
		vec = at_vector(&obj->data.mesh.obj_3d->vertices, face->points[2].vertice_id - 1);
		triangle.p2 = *vec;
		triangle.color.rgb.r = 0;
		triangle.color.rgb.g = 255;
		triangle.color.rgb.b = 0;
		t_object	o;
		o.data.triangle = triangle;
		if (get_closest_distance_ptr(intersect_triangle(&o, ray), t, &t))
		{
			data = ray->data;
		}
		++i;
	}
	if (t == -1)
		return (-1);
	ray->data = data;
	get_hitpos(ray, t);
	return (t);
}
