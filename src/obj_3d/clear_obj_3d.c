/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_obj_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 05:14:14 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/16 07:00:47 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "obj_3d.h"
#include "vector.h"

void	clear_obj_3d(t_obj_3d *obj)
{
	clear_vector(&obj->faces);
	clear_vector(&obj->vertices);
	clear_vector(&obj->space_vertices);
	clear_vector(&obj->vertex_normals);
	clear_vector(&obj->texture_coordinates);
	free(obj);
}
