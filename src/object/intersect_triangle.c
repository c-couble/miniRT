/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 01:12:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "object.h"
#include "ray.h"

double	intersect_triangle(t_object *obj, t_ray *ray)
{
	double	t;

	t = intersect_cached_triangle(&obj->data.triangle.cached, ray);
	if (t == -1)
		return (-1);
	ray->data.color = obj->data.triangle.color;
	return (t);
}
