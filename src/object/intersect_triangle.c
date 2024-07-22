/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 23:08:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "vec3.h"
#include "ray.h"
#include "object.h"

static void		get_plane_from_triangle(t_triangle *tr, t_plane *p);

double	intersect_triangle(t_object *obj, t_ray *ray)
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
