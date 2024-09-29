/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bounding_boxes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:50:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 03:13:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "draw.h"
#include "object.h"

void	draw_bounding_boxes(t_engine *eng, t_vector *objs, uint32_t color)
{
	size_t		i;
	t_object	*obj;
	t_bbox		bbox;

	i = 0;
	while (i < objs->size)
	{
		obj = at_vector(objs, i);
		if (obj->type == MESH)
			draw_mesh(eng, &obj->data.mesh, color);
		else
		{
			get_bbox_from_aabb(&obj->aabb, &bbox);
			draw_bounding_box(eng, &bbox, color);
		}
		++i;
	}
}
