/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_aabb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:28:14 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 22:19:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bvh.h"
#include "vec3.h"

void	create_empty_aabb(t_aabb *aabb)
{
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &aabb->min);
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->max);
}
