/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:22:01 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 00:50:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	const double	x = a->y * b->z - a->z * b->y;
	const double	y = a->z * b->x - a->x * b->z;
	const double	z = a->x * b->y - a->y * b->x;

	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}
