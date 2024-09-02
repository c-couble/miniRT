/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 08:00:17 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "quaternion.h"
#include "ray.h"
#include "util.h"
#include "ft_math.h"
#include "vec3.h"
#include <math.h>

#define SIZE 10

double	intersect_plane(t_object *obj, t_ray *ray)
{
	double	t;
	t_vec3	local;

	t = solve_plane_equation(&obj->data.plane, ray);
	if (t == -1)
		return (-1);
	ray->data.color = obj->data.plane.color;
	ray->data.normal = obj->data.plane.normal;
	get_hitpos(ray, t);
	ray->data.texture = obj->optional_data.texture;
	if (ray->data.texture)
	{
		quaternion_rotate(&ray->data.hitpos, 
					&obj->data.plane.rot_axis, obj->data.plane.theta, &local);
		ray->data.u = local.x / (ray->data.texture->width / 100.);
		ray->data.v = local.y / (ray->data.texture->height / 100.);
		ray->data.u = fmod(ft_dabs(ray->data.u), 1.0);
		ray->data.v = fmod(ft_dabs(ray->data.v), 1.0);
		if (local.x < 0)
			ray->data.u = 1 - ray->data.u;
		if (local.y < 0)
			ray->data.v = 1 - ray->data.v;
	}
	return (t);
}
