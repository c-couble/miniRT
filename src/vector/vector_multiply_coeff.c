/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply_coeff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:00:50 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/05 01:19:08 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

void	vector_multiply_coeff(t_vector3d *vec, double x)
{
	vec->x *= x;
	vec->y *= x;
	vec->z *= x;
}
