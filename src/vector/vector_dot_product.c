/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:13:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/03 01:18:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

double	vector_dot_product(t_vector3d *vec1, t_vector3d *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}
