/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:51:53 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/04 01:39:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "ft_mem.h"

static int	loop_hook(t_engine *engine);

void	run_loop(t_engine *engine)
{
	mlx_loop_hook(engine->mlx.mlx, loop_hook, engine);
	mlx_loop(engine->mlx.mlx);
}

static int	loop_hook(t_engine *engine)
{
	static int	i = 0;

	while (i)
		;
	ft_memset(engine->mlx.addr, 0,
		engine->mlx.width * engine->mlx.height * sizeof(t_color));
	render_frame(engine);
	mlx_put_image_to_window(engine->mlx.mlx, engine->mlx.mlx_window,
		engine->mlx.img, 0, 0);
	++i;
	return (0);
}
