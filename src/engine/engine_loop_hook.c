/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:54:41 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 02:53:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "ft_mem.h"

void	engine_loop_hook(t_engine *engine)
{
	if (engine->scene.camera.should_render == 0)
		return ;
	ft_memset(engine->mlx.addr, 0,
		engine->mlx.width * engine->mlx.height * sizeof(t_color));
	render_frame(engine);
	mlx_put_image_to_window(engine->mlx.mlx, engine->mlx.mlx_window,
		engine->mlx.img, 0, 0);
	engine->scene.camera.should_render = 0;
}
