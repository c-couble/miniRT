/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_aabb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:56:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 17:48:13 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "quaternion.h"
#include "vec3.h"

void	get_cylinder_aabb(t_cylinder *para, t_object *obj)
{
	t_vec3	local_pos;
	t_vec3	tmp;

	quaternion_rotate(&para->pos, &para->rot_axis, para->theta, &local_pos);
	obj->aabb.min.x = local_pos.x - para->radius;
	obj->aabb.min.y = local_pos.y - para->radius;
	obj->aabb.min.z = local_pos.z;
	obj->aabb.max.x = local_pos.x + para->radius;
	obj->aabb.max.y = local_pos.y + para->radius;
	obj->aabb.max.z = local_pos.z + para->height;
	quaternion_rotate(&obj->aabb.min, &para->rot_axis, -para->theta, &obj->aabb.min);
	quaternion_rotate(&obj->aabb.max, &para->rot_axis, -para->theta, &obj->aabb.max);
	tmp = para->axis;
	vec3_scale(&tmp, para->height / 2);
	vec3_subtract(&para->pos, &tmp, &obj->aabb.center);
	get_bounding_box(&obj->aabb);
}
