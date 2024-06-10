/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/10 00:44:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "math_util.h"
#include "util.h"
#include "vector3d.h"
#include "ray.h"
#include "object.h"
#include <stdio.h>

static double triangle_area(t_vector3d *a, t_vector3d *b, t_vector3d *c);

int bsp(t_vector3d *a, t_vector3d *b, t_vector3d *c, t_vector3d *point)
{
	double	base_ab_area = triangle_area(a, b, point);
	double	base_ac_area = triangle_area(a, c, point);
	double	base_bc_area = triangle_area(b, c, point);
	double	abc_area = triangle_area(a, b, c);

	if (base_ab_area + base_ac_area + base_bc_area == abc_area)
		return (1);
	return (0);
}

static double triangle_area(t_vector3d *a, t_vector3d *b, t_vector3d *c)
{
	double	 abx = a->x - b->x;
	double	 aby = a->y - b->y;
	double	 acx = a->x - c->x;
	double	 acy = a->y - c->y;

	double	 cross_product = abx * acy - aby * acx;
	double	 area = cross_product / 2.0f;
	if (area < 0)
		area = area * -1;
	return (area);
}

double	intersect_triangle(t_object *obj, t_ray *ray)
{
	t_triangle tr = obj->data.triangle;
	t_vector3d s1;
	t_vector3d s2;
	t_vector3d normal;
	vector_subtract(&tr.p1 , &tr.p0, &s1);
	vector_subtract(&tr.p2 , &tr.p0, &s2);
	vector_cross_product(&s1, &s2, &normal);
	vector_normalize(&normal);
//	printf("triangle normal is x = %lf, y = %lf, z = %lf\n", normal.x, normal.y, normal.z);

	t_plane plane;
	plane.coordinates = tr.p0;
	plane.orientation = normal;
	plane.color = tr.color;
	ray->color = tr.color;
	double t = solve_plane_equation(&plane, ray);
	t_vector3d point;
	point.x = ray->startpos.x + t * ray->ray.x;
	point.y = ray->startpos.y + t * ray->ray.y;
	point.z = ray->startpos.z + t * ray->ray.z;
	if (bsp(&tr.p0, &tr.p1, &tr.p2, &point))
		return (t);
	return (-1);
}
