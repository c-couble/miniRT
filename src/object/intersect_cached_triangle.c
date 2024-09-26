/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cached_triangle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 03:16:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/26 06:28:51 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "defines.h"
#include "ft_math.h"
#include "object/triangle.h"
#include "util.h"
#include "vec3.h"

double	intersect_cached_triangle(t_cached_triangle *triangle, t_ray *ray)
{
	t_vec3	T;
	t_vec3	P;
	t_vec3	Q;

	vec3_subtract(&ray->startpos, &triangle->points[0], &T);
	vec3_cross(&ray->ray, &triangle->e2, &P);
	vec3_cross(&T, &triangle->e1, &Q);
	double dot = vec3_dot(&P, &triangle->e1);
	if (double_equals(dot, 0))
		return (-1);
	double inv_det = 1 / dot;
	double u = inv_det * vec3_dot(&P, &T);
	if (u < 0 || u > 1)
		return (-1);
	double v = inv_det * vec3_dot(&Q, &ray->ray);
	if (v < 0 || u + v > 1)
		return (-1);
	double t = inv_det * vec3_dot(&Q, &triangle->e2);
	if (t < INACCURATE_ZERO)
		return (-1);

	ray->data.normal = triangle->normal;
	ray->data.u = (1 - u - v) * triangle->point_tx[0]->x
		+ u * triangle->point_tx[1]->x
		+ v * triangle->point_tx[2]->x;
	ray->data.v = (1 - u - v) * triangle->point_tx[0]->y
		+ u * triangle->point_tx[1]->y
		+ v * triangle->point_tx[2]->y;
	ray->data.u = ft_dabs(fmod(ray->data.u, 1));
	ray->data.v = ft_dabs(fmod(ray->data.v, 1));
	if (triangle->material && triangle->material->texture)
	{
		ray->data.texture = triangle->material->texture;
	}
	else
		ray->data.texture = NULL;
	return (t);
}
