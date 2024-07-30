/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:01:49 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 07:55:58 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"

void	lock_camera(t_engine *engine)
{
	if (engine->scene.camera.locked)
	{
		engine->scene.camera.locked = 0;
		engine->scene.camera.pixel_square_size = DEFAULT_RAY_SIZE;
	}
	else
	{
		engine->scene.camera.locked = 1;
		engine->scene.camera.should_render = 1;
		engine->scene.camera.pixel_square_size = 1;
	}
}
