/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/05 00:59:37 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "vector3d.h"
#include "ray.h"
#include "object.h"

double	intersect_plane(t_object *obj, t_ray *ray)
{
	double dot_ray_n = vector_dot_product(&ray->ray, &obj->data.plane.orientation);
	if (dot_ray_n == 0)
		return (1);
	double ax = obj->data.plane.orientation.x * obj->data.plane.coordinates.x;
	double by = obj->data.plane.orientation.y * obj->data.plane.coordinates.y;
	double cz = obj->data.plane.orientation.z * obj->data.plane.coordinates.z;
	double d = -(ax + by + cz);

	ax = obj->data.plane.orientation.x * ray->startpos.x;
	by = obj->data.plane.orientation.y * ray->startpos.y;
	cz = obj->data.plane.orientation.z * ray->startpos.z;
	double t = (-(ax + by + cz + d)) / dot_ray_n;
	if (t <= INACCURATE_ZERO || t >= ray->maxlen)
		return (-1);
	ray->color = obj->data.plane.color;
	return (t);
}
