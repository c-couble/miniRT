/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/09 23:15:37 by lespenel         ###   ########.fr       */
/*   Updated: 2024/06/09 14:27:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "util.h"

double	intersect_plane(t_object *obj, t_ray *ray)
{
	ray->color = obj->data.plane.color;
	return (solve_plane_equation(&obj->data.plane, ray));
}
