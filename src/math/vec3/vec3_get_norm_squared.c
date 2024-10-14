/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_get_norm_squared.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:44:54 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 21:45:16 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"

double	vec3_get_norm_squared(t_vec3 *vec)
{
	return (powl(vec->x, 2) + powl(vec->y, 2) + powl(vec->z, 2));
}
