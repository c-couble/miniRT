/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:51:53 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/11 02:30:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_mem.h"
#include "mlx.h"

void	engine_loop_hook(t_engine *engine)
{
	if (engine->scene.camera.should_render == 0)
		return ;
	ft_memset(engine->mlx.addr, 0,
		engine->mlx.width * engine->mlx.height * sizeof(t_color));
	render_frame(engine);
	mlx_put_image_to_window(engine->mlx.mlx, engine->mlx.mlx_window,
		engine->mlx.img, 0, 0);
	if (engine->scene.camera.locked)
	{
		engine->scene.camera.last_frame_time = 0;
		engine->scene.camera.pixel_square_size = 1;
		if (engine->sampling)
			engine->sample_nb++;
	}
	if (engine->sampling && engine->scene.camera.locked)
		engine->scene.camera.should_render = 1;
	else
		engine->scene.camera.should_render = 0;
}
