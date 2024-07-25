/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/25 03:36:45 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "vec3.h"
#include "ray.h"
#include "object.h"
#include "defines.h"
#include <stdio.h>
#include <unistd.h>

double	intersect_triangle2(t_object *obj, t_ray *ray);

double	intersect_triangle(t_object *obj, t_ray *ray)
{
	t_vec3	O = ray->startpos;
	t_vec3	D = ray->ray;
	t_vec3	T;
	t_vec3	E1;
	t_vec3	E2;
	t_vec3	P;
	t_vec3	Q;

	vec3_subtract(&O, &obj->data.triangle.p0, &T);
	vec3_subtract(&obj->data.triangle.p1, &obj->data.triangle.p0, &E1);
	vec3_subtract(&obj->data.triangle.p2, &obj->data.triangle.p0, &E2);
	vec3_cross_product(&D, &E2, &P);
	vec3_cross_product(&T, &E1, &Q);
	double inv_det = 1 / vec3_dot_product(&P, &E1);
	double u = inv_det * vec3_dot_product(&P, &T);
	if (u < 0 || u > 1)
		return (-1);
	double v = inv_det * vec3_dot_product(&Q, &D);
	if (v < 0 || u + v > 1)
		return (-1);
	double t = inv_det * vec3_dot_product(&Q, &E2);
	if (t < INACCURATE_ZERO)
		return (-1);
	//double t2 = intersect_triangle2(obj, ray);
	//printf("%lf %lf\n", t, t2);
	//ray->data.color = obj->data.triangle.color;

	ray->data.color.rgb.r = u * 255;
	ray->data.color.rgb.g = v * 255;
	ray->data.color.rgb.b = (1 - u - v) * 255;
	vec3_cross_product(&E1, &E2, &ray->data.normal);
	//vec3_normalize(&normal);
	return (t);
}

static void		get_plane_from_triangle(t_triangle *tr, t_plane *p);

double	intersect_triangle2(t_object *obj, t_ray *ray)
{
	t_plane		plane;
	t_triangle	tr;
	t_vec3		point;
	double		t;

	get_plane_from_triangle(&obj->data.triangle, &plane);
	tr = obj->data.triangle;
	ray->data.color = tr.color;
	ray->data.normal = plane.normal;
	t = solve_plane_equation(&plane, ray);
	point.x = ray->startpos.x + t * ray->ray.x;
	point.y = ray->startpos.y + t * ray->ray.y;
	point.z = ray->startpos.z + t * ray->ray.z;
	t_vec3 edge0;
	vec3_subtract(&tr.p1, &tr.p0, &edge0);
	t_vec3 edge1;
	vec3_subtract(&tr.p2, &tr.p1, &edge1);
	t_vec3 edge2;
	vec3_subtract(&tr.p0, &tr.p2, &edge2);
	t_vec3 C0;
	vec3_subtract(&point, &tr.p0, &C0);
	t_vec3 C1;
	vec3_subtract(&point, &tr.p1, &C1);
	t_vec3 C2;
	vec3_subtract(&point, &tr.p2, &C2);
	
	t_vec3	prout0;
	if (vec3_dot_product(&plane.normal, vec3_cross_product(&edge0, &C0, &prout0)) > 0
		&& vec3_dot_product(&plane.normal, vec3_cross_product(&edge1, &C1, &prout0)) > 0
    	&& vec3_dot_product(&plane.normal, vec3_cross_product(&edge2, &C2, &prout0)) > 0) return t; // P is inside the triangle
	return (-1);
}
//88157909

static void	get_plane_from_triangle(t_triangle *tr, t_plane *p)
{
	t_vec3	s1;
	t_vec3	s2;
	t_vec3	normal;

	vec3_subtract(&tr->p1, &tr->p0, &s1);
	vec3_subtract(&tr->p2, &tr->p0, &s2);
	vec3_cross_product(&s1, &s2, &normal);
	//vec3_normalize(&normal);
	p->pos = tr->p0;
	p->normal = normal;
}
