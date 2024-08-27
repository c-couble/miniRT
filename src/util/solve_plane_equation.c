/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_plane_equation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:14:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/15 02:03:30 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "object/plane.h"
#include "vec3.h"
#include "ray.h"

double	solve_plane_equation(t_plane *plane, t_ray *ray)
{
	const double	dot = vec3_dot_product(&ray->ray, &plane->normal);
	const double	d = -(plane->normal.x * plane->pos.x
			+ plane->normal.y * plane->pos.y
			+ plane->normal.z * plane->pos.z);
	double			t;

	if (dot == 0)
		return (-1);
	t = (-(plane->normal.x * ray->startpos.x
				+ plane->normal.y * ray->startpos.y
				+ plane->normal.z * ray->startpos.z + d)) / dot;
	if (t <= INACCURATE_ZERO)
		return (-1);
	return (t);
}
