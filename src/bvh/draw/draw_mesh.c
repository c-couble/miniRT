/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 03:10:53 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 03:11:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "engine.h"
#include "object/mesh.h"

void	draw_mesh(t_engine *eng, t_mesh *mesh, uint32_t color)
{
	size_t	i;
	t_bbox	bbox;

	i = 0;
	while (i < mesh->triangles)
	{
		get_bbox_from_aabb(&mesh->cache[i].aabb, &bbox);
		draw_bounding_box(eng, &bbox, color);
		++i;
	}
}
