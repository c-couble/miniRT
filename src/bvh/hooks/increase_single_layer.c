/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_single_layer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:05:38 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 14:13:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	increase_single_layer(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	if (engine->scene.bvh.bvh_mode == NONE)
		return ;
	if (engine->scene.bvh.bvh_mode == FULL_LAYER)
		engine->scene.bvh.bvh_mode = SINGLE_LAYER;
	engine->scene.bvh.depth += 1;
	engine->scene.bvh.depth %= engine->scene.bvh.max_depth + 1;
	engine->scene.camera.should_render = 1;
}
