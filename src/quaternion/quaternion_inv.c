/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_inv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:48:20 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 07:34:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vec3.h"

void	quaternion_inv(t_quaternion *q, t_quaternion *out)
{
	double	denom;

	denom = (q->a * q->a + vec3_dot_product(&q->vec, &q->vec));
	out->a = q->a / denom;
	out->vec = q->vec;
	vec3_scale(&out->vec, -1);
	vec3_scale(&out->vec, 1 / denom);
}
