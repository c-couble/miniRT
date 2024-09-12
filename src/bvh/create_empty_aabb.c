/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_aabb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:28:14 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 23:30:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "vec3.h"
#include <float.h>

void	create_empty_aabb(t_aabb *aabb)
{
	vec3_create(DBL_MIN, DBL_MIN, DBL_MIN, &aabb->min);
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->max);
}
