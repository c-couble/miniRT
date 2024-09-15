/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrease_depth_manual.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:09:57 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 16:10:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	decrease_depth_manual(t_engine *engine)
{
	if (engine->scene.camera.bvh_mode == NONE)
		return ;
	if (engine->scene.camera.bvh_mode == PERSISTENT)
		engine->scene.camera.bvh_mode = MANUAL;
	engine->scene.bvh_depth -= 1;
	if (engine->scene.bvh_depth < 0)
		engine->scene.bvh_depth = engine->scene.bvh_m_depth;
	engine->scene.camera.should_render = 1;
}
