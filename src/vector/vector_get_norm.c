/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:04:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/03 01:10:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

double	vector_get_norm(t_vector3d *vec)
{
	return (powl(vec->x, 2) + powl(vec->y, 2) + powl(vec->z, 2));
}
