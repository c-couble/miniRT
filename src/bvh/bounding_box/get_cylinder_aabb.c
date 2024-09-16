/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_aabb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:56:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 19:58:10 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "util.h"

static void	get_radial_vec(t_vec3 *ra, t_vec3 *rb, t_vec3 *axis, double radius);
static void	get_face(t_vec3 face[4], t_vec3 *mid, t_vec3 *ra, t_vec3 *rb);

void	get_cylinder_aabb(t_cylinder *cyl, t_object *obj)
{
	t_vec3	top_mid;
	t_vec3	bottom_mid;
	t_vec3	radial_a;
	t_vec3	radial_b;
	t_bbox	b_box;

	bottom_mid = cyl->pos;
	top_mid = cyl->axis;
	vec3_scale(&top_mid, cyl->height);
	vec3_add(&cyl->pos, &top_mid, &top_mid);
	get_radial_vec(&radial_a, &radial_b, &cyl->axis, cyl->radius);
	get_face(b_box.top, &top_mid, &radial_a, &radial_b);
	get_face(b_box.bottom, &bottom_mid, &radial_a, &radial_b);
	get_aabb_from_bbox(&b_box, &obj->aabb);
	obj->aabb.box = b_box;
	obj->aabb.center = cyl->center;
}

static void	get_radial_vec(t_vec3 *ra, t_vec3 *rb, t_vec3 *axis, double radius)
{
	t_vec3	u;

	vec3_create(0, 0, 1, &u);
	if (double_equals(axis->z, 1) || double_equals(axis->z, -1))
		vec3_create(1, 0, 0, ra);
	else
		vec3_normalize(vec3_cross(axis, &u, ra));
	vec3_normalize(vec3_cross(ra, axis, rb));
	vec3_scale(ra, radius);
	vec3_scale(rb, radius);
}

static void	get_face(t_vec3 face[4], t_vec3 *mid, t_vec3 *ra, t_vec3 *rb)
{
	t_vec3	plus;
	t_vec3	minus;

	vec3_add(ra, rb, &plus);
	vec3_subtract(ra, rb, &minus);
	vec3_subtract(mid, &minus, &face[0]);
	vec3_subtract(mid, &plus, &face[1]);
	vec3_add(mid, &minus, &face[2]);
	vec3_add(mid, &plus, &face[3]);
}
