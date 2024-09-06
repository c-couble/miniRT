/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/06 10:15:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "defines.h"
#include "ft_math.h"
#include "object.h"
#include "quaternion.h"
#include "util.h"
#include "vec3.h"

static void	get_uv(t_ray *ray, t_plane *plane);

double	intersect_plane(t_object *obj, t_ray *ray)
{
	double	t;

	t = solve_plane_equation(&obj->data.plane, ray);
	if (t == -1)
		return (-1);
	ray->data.normal = obj->data.plane.normal;
	ray->data.color = obj->data.plane.color;
	get_hitpos(ray, t);
	ray->data.texture = obj->optional_data.texture;
	get_uv(ray, &obj->data.plane);
	return (t);
}

static void	get_uv(t_ray *ray, t_plane *plane)
{
	t_vec3	local;

	quaternion_rotate(&ray->data.hitpos,
		&plane->rot_axis, plane->theta, &local);
	if (ray->data.texture)
	{
		ray->data.u = local.x / (ray->data.texture->width / TILE_DIVIDER);
		ray->data.v = local.y / (ray->data.texture->height / TILE_DIVIDER);
	}
	else
	{
		ray->data.u = local.x / (TILE_DIVIDER);
		ray->data.v = local.y / (TILE_DIVIDER);
	}
	ray->data.u = fmod(ft_dabs(ray->data.u), 1.0);
	ray->data.v = fmod(ft_dabs(ray->data.v), 1.0);
	if (local.x < 0)
		ray->data.u = 1 - ray->data.u;
	if (local.y < 0)
		ray->data.v = 1 - ray->data.v;
}
