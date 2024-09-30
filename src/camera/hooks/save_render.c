/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:41:21 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 15:57:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"

void	save_render(t_engine *engine)
{
	if (engine->render_size == 0)
		return ;
	mlx_mouse_show(engine->mlx.mlx, engine->mlx.mlx_window);
	engine->scene.camera.locked = 1;
	engine->scene.camera.save = 1;
	engine->scene.camera.should_render = 1;
	engine->scene.camera.pixel_square_size = 1;
}
