/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:51:12 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/01 03:10:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "vec3.h"

t_vec3	*vec3_random(t_vec3 *vec, double min, double max)
{
	t_vec3	v;

	v.x = rand_range(min, max);
	v.y = rand_range(min, max);
	v.z = rand_range(min, max);
	vec->x = vec->x * v.x;
	vec->y = vec->y * v.y;
	vec->z = vec->z * v.z;
	return (vec);
}
