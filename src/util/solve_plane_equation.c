/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_plane_equation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:14:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/09 19:13:43 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "object/plane.h"
#include "vector3d.h"
#include "ray.h"

double	solve_plane_equation(t_plane *plane, t_ray *ray)
{
	const double	dot_ray_n = vector_dot_product(&ray->ray, &plane->orientation);
	if (dot_ray_n == 0)
		return (1);
	double ax = plane->orientation.x * plane->coordinates.x;
	double by = plane->orientation.y * plane->coordinates.y;
	double cz = plane->orientation.z * plane->coordinates.z;
	double d = -(ax + by + cz);

	ax = plane->orientation.x * ray->startpos.x;
	by = plane->orientation.y * ray->startpos.y;
	cz = plane->orientation.z * ray->startpos.z;
	double t = (-(ax + by + cz + d)) / dot_ray_n;
	if (t <= INACCURATE_ZERO)
		return (-1);
	return (t);
}
