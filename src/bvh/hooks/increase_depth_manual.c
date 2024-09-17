/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_depth_manual.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:05:38 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:13:04 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	increase_depth_manual(t_engine *engine)
{
	if (engine->scene.bvh.bvh_mode == NONE)
		return ;
	if (engine->scene.bvh.bvh_mode == PERSISTENT)
		engine->scene.bvh.bvh_mode = MANUAL;
	engine->scene.bvh.depth += 1;
	engine->scene.bvh.depth %= engine->scene.bvh.max_depth + 1;
	engine->scene.camera.should_render = 1;
}
