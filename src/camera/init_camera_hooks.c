/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:59:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 06:20:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx_wrapper.h"

static int	init_movement_hooks(t_engine *engine);

int	init_camera_hooks(t_engine *engine)
{
	t_hook	hook;

	if (init_movement_hooks(engine) == -1)
		return (-1);
	hook = create_mlx_hook(lock_camera, engine, KEY_ENTER, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}

static int	init_movement_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(engine_loop_hook, engine, 0, LOOP);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(move_forward, engine, KEY_W, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(move_backwards, engine, KEY_S, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(move_left, engine, KEY_A, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(move_right, engine, KEY_D, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(move_up, engine, KEY_SPACE, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(move_down, engine, KEY_CONTROL, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}
