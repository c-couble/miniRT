/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_focus_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:43:09 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/25 01:53:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"

void	engine_focus_in(t_engine *engine)
{
	(void) engine;
	if (engine->scene.camera.locked == 0)
	{
		mlx_mouse_hide(engine->mlx.mlx, engine->mlx.mlx_window);
		mlx_mouse_move(engine->mlx.mlx, engine->mlx.mlx_window,
			engine->mlx.width / 2, engine->mlx.height / 2);
		engine->mlx.old_x = engine->mlx.width / 2;
		engine->mlx.old_y = engine->mlx.height / 2;
	}
}
