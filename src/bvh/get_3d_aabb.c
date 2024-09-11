/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_3d_aabb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:03:21 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 17:40:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

void	get_3d_aabb(t_aabb *aabb)
{
	vec3_create(aabb->min.x, aabb->max.y, aabb->max.z, &aabb->box.cube[0]);
	vec3_create(aabb->max.x, aabb->max.y, aabb->max.z, &aabb->box.cube[1]);
	vec3_create(aabb->max.x, aabb->min.y, aabb->max.z, &aabb->box.cube[2]);
	vec3_create(aabb->min.x, aabb->min.y, aabb->max.z, &aabb->box.cube[3]);
	vec3_create(aabb->min.x, aabb->max.y, aabb->min.z, &aabb->box.cube[4]);
	vec3_create(aabb->max.x, aabb->max.y, aabb->min.z, &aabb->box.cube[5]);
	vec3_create(aabb->max.x, aabb->min.y, aabb->min.z, &aabb->box.cube[6]);
	vec3_create(aabb->min.x, aabb->min.y, aabb->min.z, &aabb->box.cube[7]);
}
