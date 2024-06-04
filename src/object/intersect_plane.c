/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/04 02:52:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "vector3d.h"
#include "ray.h"
#include "object.h"

double	intersect_plane(t_object *obj, t_ray *ray)
{
	ray->color = obj->data.plane.color;
	if (vector_dot_product(&ray->ray, &obj->data.plane.orientation) > INACCURATE_ZERO)
	{
		ray->color = obj->data.plane.color;
		// ?? where is t
		return (2);
	}
	return (-1);
}
