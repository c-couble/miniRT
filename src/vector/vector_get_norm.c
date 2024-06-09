/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:04:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/07 15:33:37 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

double	vector_get_norm(t_vector3d *vec)
{
	return (sqrt(powl(vec->x, 2) + powl(vec->y, 2) + powl(vec->z, 2)));
}
