/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:26:44 by lespenel          #+#    #+#             */
/*   Updated: 2025/07/06 23:09:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "math_util.h"
#include "quaternion.h"
#include "object.h"
#include "ray.h"
#include "util.h"
#include "vec3.h"

static double	check_disk(t_object *obj, t_ray *ray);

double	intersect_disk(t_object *obj, t_ray *ray)
{
    return (check_disk(obj, ray));
}

static double	check_disk(t_object *obj, t_ray *ray)
{
	t_plane	plane;
	t_vec3	hitpoint;
	double	t;

	plane.pos = obj->data.disk.pos;
	plane.normal = obj->data.disk.normal;
	t = solve_plane_equation(&plane, ray);
	get_hitpos(ray, t);
	vec3_subtract(&plane.pos, &ray->data.hitpos, &hitpoint);
	if (vec3_get_norm_squared(&hitpoint) < obj->data.disk.radiussq)
	{
		ray->data.normal = plane.normal;
		vec3_scale(&hitpoint, 1 / (obj->data.disk.diameter));
		quaternion_rotate(&hitpoint, &obj->data.disk.rot_axis,
			obj->data.disk.theta, &hitpoint);
		ray->data.u = 0.5 - hitpoint.y;
		ray->data.v = 0.5 - hitpoint.x;
		set_texture_normal(obj, ray, 1);
		ray->data.color = obj->data.disk.color;
		return (t);
	}
	return (-1);
}
