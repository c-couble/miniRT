/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_aabb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:56:08 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 00:50:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "object.h"

void	get_objects_aabb(t_object *object)
{
	if (object->type == SPHERE)
		get_sphere_aabb(&object->data.sphere, &object->aabb);
	if (object->type == PARABOLOID)
		get_paraboloid_aabb(&object->data.paraboloid, &object->aabb);
	if (object->type == CYLINDER)
		get_cylinder_aabb(&object->data.cylinder, &object->aabb);
	if (object->type == MESH)
		get_mesh_aabb(&object->data.mesh, &object->aabb);
	if (object->type == TRIANGLE)
		get_cached_triangle_aabb(&object->data.triangle.cached, &object->aabb);
}
