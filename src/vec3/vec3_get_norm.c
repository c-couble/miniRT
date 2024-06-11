/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_get_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:04:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:37:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

double	vec3_get_norm(t_vec3 *vec)
{
	return (sqrt(powl(vec->x, 2) + powl(vec->y, 2) + powl(vec->z, 2)));
}
