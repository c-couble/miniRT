/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/12 20:01:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "util.h"

double	intersect_plane(t_object *obj, t_ray *ray)
{
	double	t;

	t = solve_plane_equation(&obj->data.plane, ray);
	if (t == -1)
		return (-1);
	ray->data.color = obj->data.plane.color;
	ray->data.normal = obj->data.plane.orientation;
	get_hitpos(ray, t);
	return (t);
}
