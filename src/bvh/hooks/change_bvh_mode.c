/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_bvh_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:33:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:12:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	change_bvh_mode(t_engine *engine)
{
	if (engine->scene.bvh.bvh_mode == NONE)
		engine->scene.bvh.bvh_mode = PERSISTENT;
	else
		engine->scene.bvh.bvh_mode = NONE;
	engine->scene.camera.should_render = 1;
}
