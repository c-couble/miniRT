/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalized_vector3d.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:22:06 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/07 01:01:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>
#include <stdio.h>

int	parse_normalized_vector3d(t_vec3 *vector)
{
	if (parse_vector3d(vector, -1, 1) == -1)
		return (-1);
	vec3_normalize(vector);
	return (0);
}
