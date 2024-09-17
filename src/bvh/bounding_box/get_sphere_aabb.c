/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_aabb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:35:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 15:32:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "object/sphere.h"
#include "vec3.h"

void	get_sphere_aabb(t_sphere *sphere, t_aabb *aabb)
{
	aabb->min.x = sphere->pos.x - sphere->radius;
	aabb->min.y = sphere->pos.y - sphere->radius;
	aabb->min.z = sphere->pos.z - sphere->radius;
	aabb->max.x = sphere->pos.x + sphere->radius;
	aabb->max.y = sphere->pos.y + sphere->radius;
	aabb->max.z = sphere->pos.z + sphere->radius;
	aabb->center = sphere->pos;
	get_bbox_from_aabb(aabb, &aabb->box);
}
