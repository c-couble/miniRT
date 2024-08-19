/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:51:12 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/19 14:03:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vec3.h"

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

t_vec3	*vec3_random(t_vec3 *vec, double min, double max)
{
	t_vec3	v;

	printf("randfrom%lf\n", randfrom(min, max));
	v.x = randfrom(min, max);
	v.y = randfrom(min, max);
	v.z = randfrom(min, max);
	vec->x = vec->x * v.x;
	vec->y = vec->y * v.y;
	vec->z = vec->z * v.z;
	return (vec);
}
