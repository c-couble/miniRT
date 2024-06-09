/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:00:50 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/05 01:22:08 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

void	vector_multiply(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *out)
{
	out->x = vec1->x * vec2->x;
	out->y = vec1->y * vec2->y;
	out->z = vec1->z * vec2->z;
}
