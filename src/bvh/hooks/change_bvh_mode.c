/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_bvh_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:33:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 15:57:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

void	change_bvh_mode(t_engine *engine)
{
	if (engine->scene.camera.bvh_mode == NONE)
		engine->scene.camera.bvh_mode = PERSISTENT;
	else
		engine->scene.camera.bvh_mode = NONE;
	engine->scene.camera.should_render = 1;
}
