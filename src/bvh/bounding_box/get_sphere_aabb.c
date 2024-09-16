/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_aabb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:35:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 01:43:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "vec3.h"

void	get_sphere_aabb(t_sphere *sphere, t_object *obj)
{
	obj->aabb.min.x = sphere->pos.x - sphere->radius;
	obj->aabb.min.y = sphere->pos.y - sphere->radius;
	obj->aabb.min.z = sphere->pos.z - sphere->radius;
	obj->aabb.max.x = sphere->pos.x + sphere->radius;
	obj->aabb.max.y = sphere->pos.y + sphere->radius;
	obj->aabb.max.z = sphere->pos.z + sphere->radius;
	obj->aabb.center = sphere->pos;
	get_bbox_from_aabb(&obj->aabb);
}
