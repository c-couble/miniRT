/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_aabb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:56:08 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 18:00:19 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	get_objects_ababb(t_object *object)
{
	if (object->type == SPHERE)
		get_sphere_aabb(&object->data.sphere, &object->aabb);
	if (object->type == PARABOLOID)
		get_paraboloid_aabb(&object->data.paraboloid, &object->aabb);
	if (object->type == CYLINDER)
		get_cylinder_aabb(&object->data.cylinder, &object->aabb);
}
