/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_get_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:04:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:36:47 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"

double	vec3_get_norm(t_vec3 *vec)
{
	return (sqrt(powl(vec->x, 2) + powl(vec->y, 2) + powl(vec->z, 2)));
}
