/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 16:59:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "util.h"

double	intersect_plane(t_object *obj, t_ray *ray)
{
	double	t;

	t = solve_plane_equation(&obj->data.plane, ray);
	if (t == -1)
		return (-1);
	ray->data.color = obj->data.plane.color;
	ray->data.normal = obj->data.plane.normal;
	get_hitpos(ray, t);
	return (t);
}
