/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:10:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 04:48:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "draw.h"

void	draw_bvh(t_engine *engine)
{
	if (engine->scene.camera.render_type == BOUNDING_BOX)
		draw_bounding_boxes(engine, &engine->scene.objects, WHITE);
	if (engine->scene.bvh.bvh_mode != NONE)
	{
		if (engine->scene.bvh.bvh_mode == FULL_LAYER)
			draw_bvh_from_depth(engine, engine->scene.bvh.bvh, 0);
		else
			draw_bvh_at_depth(engine, engine->scene.bvh.bvh, 0);
	}
}
