/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:32:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:38:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include <stdio.h>

double	intersect(t_object *obj, t_ray *ray)
{
	static double	(*f[])(t_object *obj, t_ray *ray) = {
	[AMBIENT_LIGHT] = NULL,
	[CAMERA] = NULL,
	[LIGHT] = NULL,
	[SPHERE] = intersect_sphere,
	[PLANE] = intersect_plane,
	[CYLINDER] = intersect_cylinder,
	[PARABOLOID] = intersect_paraboloid,
	[TRIANGLE] = intersect_triangle,
	[MESH] = intersect_mesh
	};
	double			t;

	if (f[obj->type] != NULL)
	{
		t = f[obj->type](obj, ray);
		if (t > 0)
		{
			ray->data.obj = obj;
			ray->data.materials = obj->optional_data.material;
		}
		return (t);
	}
	return (-1);
}
