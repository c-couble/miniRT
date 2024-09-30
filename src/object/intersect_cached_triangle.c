/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cached_triangle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 03:16:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 09:12:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "defines.h"
#include "ft_math.h"
#include "object/triangle.h"
#include "util.h"
#include "vec3.h"

static double	get_t(t_cached_triangle *t, t_ray *ray, t_vec3 *vt, t_vec3 *p);
static void		set_data(t_cached_triangle *t, t_ray *ray, double u, double v);
static void		gouraud(t_cached_triangle *t, t_ray *ray, double u, double v);

double	intersect_cached_triangle(t_cached_triangle *triangle, t_ray *ray)
{
	t_vec3	vec_t;
	t_vec3	vec_p;

	vec3_subtract(&ray->startpos, &triangle->points[0], &vec_t);
	vec3_cross(&ray->ray, &triangle->e2, &vec_p);
	return (get_t(triangle, ray, &vec_t, &vec_p));
}

static double	get_t(t_cached_triangle *tr, t_ray *ray, t_vec3 *vt, t_vec3 *p)
{
	t_vec3	vec_q;
	double	inv_det;
	double	u;
	double	v;
	double	t;

	vec3_cross(vt, &tr->e1, &vec_q);
	inv_det = vec3_dot(p, &tr->e1);
	if (double_equals(inv_det, 0))
		return (-1);
	inv_det = 1 / inv_det;
	u = inv_det * vec3_dot(p, vt);
	if (u < 0 || u > 1)
		return (-1);
	v = inv_det * vec3_dot(&vec_q, &ray->ray);
	if (v < 0 || u + v > 1)
		return (-1);
	t = inv_det * vec3_dot(&vec_q, &tr->e2);
	if (t < INACCURATE_ZERO)
		return (-1);
	set_data(tr, ray, u, v);
	return (t);
}

static void	set_data(t_cached_triangle *t, t_ray *ray, double u, double v)
{
	if (t->has_normals)
		gouraud(t, ray, u, v);
	else
		ray->data.normal = t->normal;
	ray->data.materials = t->material;
	if (t->material && t->point_tx[0] && t->point_tx[1] && t->point_tx[2])
	{
		ray->data.u = (1 - u - v) * t->point_tx[0]->x
			+ u * t->point_tx[1]->x
			+ v * t->point_tx[2]->x;
		ray->data.v = (1 - u - v) * t->point_tx[0]->y
			+ u * t->point_tx[1]->y
			+ v * t->point_tx[2]->y;
		ray->data.u = ft_dabs(fmod(ray->data.u, 1));
		ray->data.v = ft_dabs(fmod(ray->data.v, 1));
		ray->data.texture = t->material->texture;
		ray->data.normal_map = t->material->normal_map;
	}
	else
	{
		ray->data.texture = NULL;
		ray->data.normal_map = NULL;
	}
}

static void	gouraud(t_cached_triangle *t, t_ray *ray, double u, double v)
{
	t_vec3	tmp1;
	t_vec3	tmp2;

	tmp1 = t->normals[0];
	tmp2 = t->normals[1];
	vec3_scale(&tmp1, 1 - u - v);
	vec3_scale(&tmp2, u);
	vec3_add(&tmp1, &tmp2, &ray->data.normal);
	tmp1 = t->normals[2];
	vec3_scale(&tmp1, v);
	vec3_add(&ray->data.normal, &tmp1, &ray->data.normal);
	vec3_normalize(&ray->data.normal);
}
