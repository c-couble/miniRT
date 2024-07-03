/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/03 09:27:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "util.h"
#include "vec3.h"
#include "ray.h"
#include "object.h"

static void		get_plane_from_triangle(t_triangle *tr, t_plane *p);
static int		bsp(t_vec3 *a, t_vec3 *b, t_vec3 *c, t_vec3 *p);
static double	triangle_area(t_vec3 *a, t_vec3 *b, t_vec3 *c);

double	intersect_triangle(t_object *obj, t_ray *ray)
{
	t_plane		plane;
	t_triangle	tr;
	double		t;

	get_plane_from_triangle(&obj->data.triangle, &plane);
	tr = obj->data.triangle;
	ray->data.color = tr.color;
	t = solve_plane_equation(&plane, ray);
	get_hitpos(ray, t);
	ray->data.normal = plane.normal;
	if (bsp(&tr.p0, &tr.p1, &tr.p2, &ray->data.hitpos))
		return (t);
	return (-1);
}

static void	get_plane_from_triangle(t_triangle *tr, t_plane *p)
{
	t_vec3	s1;
	t_vec3	s2;
	t_vec3	normal;

	vec3_subtract(&tr->p1, &tr->p0, &s1);
	vec3_subtract(&tr->p2, &tr->p1, &s2);
	vec3_cross_product(&s1, &s2, &normal);
	vec3_normalize(&normal);
	p->pos = tr->p0;
	p->normal.x = normal.x;
	p->normal.y = normal.y;
	p->normal.z = normal.z;
}

static int	bsp(t_vec3 *a, t_vec3 *b, t_vec3 *c, t_vec3 *point)
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
	if (sum_area <= abc_area + INACCURATE_ZERO
		&& sum_area >= abc_area - INACCURATE_ZERO)
		return (1);
	return (0);
}

static double	triangle_area(t_vec3 *a, t_vec3 *b, t_vec3 *c)
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
