/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_plane_equation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:14:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/12 01:25:37 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "object/plane.h"
#include "vec3.h"
#include "ray.h"

double	solve_plane_equation(t_plane *plane, t_ray *ray)
{
	const double	dot = vec3_dot_product(&ray->ray, &plane->orientation);
	const double	d = -(plane->orientation.x * plane->coordinates.x
			+ plane->orientation.y * plane->coordinates.y
			+ plane->orientation.z * plane->coordinates.z);
	double			t;

	if (dot == 0)
		return (-1);
	t = (-(plane->orientation.x * ray->startpos.x
				+ plane->orientation.y * ray->startpos.y
				+ plane->orientation.z * ray->startpos.z + d)) / dot;
	if (t <= INACCURATE_ZERO)
		return (-1);
	return (t);
}
