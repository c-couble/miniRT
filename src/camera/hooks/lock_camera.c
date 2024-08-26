/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:01:49 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 05:39:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "mlx.h"

void	lock_camera(t_engine *engine)
{
	if (engine->scene.camera.locked)
	{
		mlx_mouse_hide(engine->mlx.mlx, engine->mlx.mlx_window);
		engine->scene.camera.locked = 0;
		engine->scene.camera.pixel_square_size = DEFAULT_RAY_SIZE;
	}
	else
	{
		mlx_mouse_show(engine->mlx.mlx, engine->mlx.mlx_window);
		engine->scene.camera.locked = 1;
		engine->scene.camera.should_render = 1;
		engine->scene.camera.pixel_square_size = 1;
	}
}
