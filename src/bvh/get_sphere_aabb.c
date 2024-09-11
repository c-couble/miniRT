/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_aabb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:35:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 17:16:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object/sphere.h"
#include "vec3.h"

void	get_sphere_aabb(t_aabb *aabb, t_sphere *sphere)
{
	aabb->min.x = sphere->pos.x - sphere->radius;
	aabb->min.y = sphere->pos.y - sphere->radius;
	aabb->min.z = sphere->pos.z - sphere->radius;
	aabb->max.x = sphere->pos.x + sphere->radius;
	aabb->max.y = sphere->pos.y + sphere->radius;
	aabb->max.z = sphere->pos.z + sphere->radius;
	get_3d_aabb(aabb);
}
