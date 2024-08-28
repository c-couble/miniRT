/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:51:12 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/28 06:13:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vec3.h"

static double	randf_range(double min, double max);

t_vec3	*vec3_random(t_vec3 *vec, double min, double max)
{
	t_vec3	v;

	v.x = randf_range(min, max);
	v.y = randf_range(min, max);
	v.z = randf_range(min, max);
	vec->x = vec->x * v.x;
	vec->y = vec->y * v.y;
	vec->z = vec->z * v.z;
	return (vec);
}

static double	randf_range(double min, double max)
{
	double	range;
	double	div;

	range = (max - min);
	div = RAND_MAX / range;
	return (min + (rand() / div));
}
