/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/10 14:21:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "util.h"
#include "vector3d.h"
#include "ray.h"
#include "object.h"
#include <stdio.h>

static void		get_plane_from_triangle(t_triangle *tr, t_plane *p);
static int		bsp(t_vector3d *a, t_vector3d *b, t_vector3d *c, t_vector3d *p);
static double	triangle_area(t_vector3d *a, t_vector3d *b, t_vector3d *c);

double	intersect_triangle(t_object *obj, t_ray *ray)
{
	t_plane		plane;
	t_triangle	tr;
	t_vector3d	point;
	double		t;

	get_plane_from_triangle(&obj->data.triangle, &plane);
	tr = obj->data.triangle;
	ray->color = tr.color;
	t = solve_plane_equation(&plane, ray);
	point.x = ray->startpos.x + t * ray->ray.x;
	point.y = ray->startpos.y + t * ray->ray.y;
	point.z = ray->startpos.z + t * ray->ray.z;
	if (bsp(&tr.p0, &tr.p1, &tr.p2, &point))
		return (t);
	return (-1);
}

static void	get_plane_from_triangle(t_triangle *tr, t_plane *p)
{
	t_vector3d	s1;
	t_vector3d	s2;
	t_vector3d	normal;

	vector_subtract(&tr->p1, &tr->p0, &s1);
	vector_subtract(&tr->p2, &tr->p0, &s2);
	vector_cross_product(&s1, &s2, &normal);
	vector_normalize(&normal);
	p->coordinates = tr->p0;
	p->orientation = normal;
}

static int	bsp(t_vector3d *a, t_vector3d *b, t_vector3d *c, t_vector3d *point)
{
	double	base_ab_area;
	double	base_ac_area;
	double	base_bc_area;
	double	abc_area;
	double	sum_area;

	base_ab_area = triangle_area(a, b, point);
	base_ac_area = triangle_area(a, c, point);
	base_bc_area = triangle_area(b, c, point);
	abc_area = triangle_area(a, b, c);
	sum_area = base_ab_area + base_ac_area + base_bc_area;
	if (sum_area < abc_area + INACCURATE_ZERO
		&& sum_area > abc_area - INACCURATE_ZERO)
		return (1);
	return (0);
}

static double	triangle_area(t_vector3d *a, t_vector3d *b, t_vector3d *c)
{
	double	abx;
	double	aby;
	double	acx;
	double	acy;
	double	area;

	abx = a->x - b->x;
	aby = a->y - b->y;
	acx = a->x - c->x;
	acy = a->y - c->y;
	area = (abx * acy - aby * acx) / 2.0f;
	if (area < 0)
		area = area * -1;
	return (area);
}
