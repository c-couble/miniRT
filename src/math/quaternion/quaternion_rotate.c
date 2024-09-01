/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:53:06 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:36:37 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "quaternion.h"
#include "vec3.h"

void	quaternion_rotate(t_vec3 *p, t_vec3 *axis, double angle, t_vec3 *out)
{
	t_quaternion	q;
	t_quaternion	point;
	t_quaternion	inv_q;
	double			half_angle;

	half_angle = angle / 2;
	q.a = cos(half_angle);
	q.vec = *axis;
	vec3_scale(&q.vec, sin(half_angle));
	point.a = 0;
	point.vec = *p;
	quaternion_inv(&q, &inv_q);
	quaternion_mult(&q, &point, &point);
	quaternion_mult(&point, &inv_q, &point);
	*out = point.vec;
}
