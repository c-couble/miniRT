/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:32:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/09 23:26:17 by lespenel         ###   ########.fr       */
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
	};

	if (f[obj->type] != NULL)
	{
		return (f[obj->type](obj, ray));
	}
	return (-1);
}
