/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_depth_persistent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:06:53 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 16:08:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	increase_depth_persistent(t_engine *engine)
{
	if (engine->scene.camera.bvh_mode == NONE)
		return ;
	if (engine->scene.camera.bvh_mode == MANUAL)
		engine->scene.camera.bvh_mode = PERSISTENT;
	engine->scene.bvh_depth += 1;
	engine->scene.bvh_depth %= engine->scene.bvh_m_depth + 1;
	engine->scene.camera.should_render = 1;
}
