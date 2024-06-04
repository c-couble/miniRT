/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_substract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:25:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/04 02:26:12 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

void	vector_subtract(t_vector3d *vec1, t_vector3d *vec2, t_vector3d *out)
{
	out->x = vec1->x - vec2->x;
	out->y = vec1->y - vec2->y;
	out->z = vec1->z - vec2->z;
}
