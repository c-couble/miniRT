/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:01:49 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/11 02:32:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "mlx.h"
#include "ft_mem.h"

void	lock_camera(t_engine *engine)
{
	if (engine->scene.camera.locked)
	{
		mlx_mouse_hide(engine->mlx.mlx, engine->mlx.mlx_window);
		engine->scene.camera.locked = 0;
		engine->scene.camera.pixel_square_size = DEFAULT_RAY_SIZE;
		engine->scene.camera.last_frame_time = 0;
		ft_memset(engine->samples, 0, engine->samples_size);
		engine->sample_nb = 1;
	}
	else
	{
		mlx_mouse_show(engine->mlx.mlx, engine->mlx.mlx_window);
		engine->scene.camera.locked = 1;
		engine->scene.camera.should_render = 1;
		engine->scene.camera.pixel_square_size = 1;
		engine->sample_nb = 1;
	}
}
