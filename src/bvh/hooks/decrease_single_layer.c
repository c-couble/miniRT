/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrease_single_layer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:09:57 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/18 00:48:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	decrease_single_layer(t_engine *engine)
{
	if (engine->scene.bvh.bvh_mode == NONE)
		return ;
	if (engine->scene.bvh.bvh_mode == FULL_LAYER)
		engine->scene.bvh.bvh_mode = SINGLE_LAYER;
	engine->scene.bvh.depth -= 1;
	if (engine->scene.bvh.depth < 0)
		engine->scene.bvh.depth = engine->scene.bvh.max_depth;
	engine->scene.camera.should_render = 1;
}
