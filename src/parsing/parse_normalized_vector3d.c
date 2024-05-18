/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalized_vector3d.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:22:06 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/15 18:20:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

int	parse_normalized_vector3d(t_vector3d *vector)
{
	if (parse_vector3d(vector, -1, 1) == -1)
		return (-1);
	if (sqrt(powl(vector->x, 2) + powl(vector->y, 2) + powl(vector->z, 2)) != 1)
		return (-1);
	return (0);
}
