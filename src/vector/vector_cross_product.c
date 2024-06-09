/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross_product.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:22:01 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/05 05:42:40 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

void	vector_cross_product(t_vector3d *a, t_vector3d *b, t_vector3d *out)
{
	const double	x = a->y * b->z - a->z * b->y;
	const double	y = a->z * b->x - a->x * b->z;
	const double	z = a->x * b->y - a->y * b->x;

	out->x = x;
	out->y = y;
	out->z = z;
}
