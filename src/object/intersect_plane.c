/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:45:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/19 15:52:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "util.h"
#include "ft_math.h"
#include <math.h>

double	intersect_plane(t_object *obj, t_ray *ray)
{
	double	t;

	t = solve_plane_equation(&obj->data.plane, ray);
	if (t == -1)
		return (-1);
	ray->data.normal = obj->data.plane.normal;
	get_hitpos(ray, t);
	if (obj->material.checker)
	{
	 	int x_index = ray->data.hitpos.x / obj->material.checker - 100.5;
		int y_index = ray->data.hitpos.y / obj->material.checker - 100.5;
		if ((x_index + y_index) % 2 == 0)
		{
			ray->data.color.rgb.r = 225;
			ray->data.color.rgb.g = 225;
			ray->data.color.rgb.b = 225;
		}
		else {
			ray->data.color.rgb.r = 070;
			ray->data.color.rgb.g = 070;
			ray->data.color.rgb.b = 070;
		}
	}
	else
		ray->data.color = obj->data.plane.color;
	return (t);
}
