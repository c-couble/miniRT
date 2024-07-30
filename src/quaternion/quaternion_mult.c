/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:35:30 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 07:51:14 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vec3.h"

void	quaternion_mult(t_quaternion *a, t_quaternion *b, t_quaternion *out)
{
	t_quaternion	tmp;
	t_vec3			veca;
	t_vec3			vecb;

	tmp.a = a->a * b->a - vec3_dot_product(&a->vec, &b->vec);
	veca = a->vec;
	vecb = b->vec;
	vec3_scale(&veca, b->a);
	vec3_scale(&vecb, a->a);
	vec3_cross_product(&a->vec, &b->vec, &tmp.vec);
	vec3_add(&tmp.vec, &veca, &tmp.vec);
	vec3_add(&tmp.vec, &vecb, &tmp.vec);
	*out = tmp;
}
