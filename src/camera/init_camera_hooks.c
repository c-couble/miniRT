/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:59:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 10:41:05 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "keyboard.h"
#include "mlx_wrapper.h"
#include "object/camera.h"

static int	init_movement_hooks(t_engine *engine);
static int	init_rotation_hooks(t_engine *engine);

int	init_camera_hooks(t_engine *engine)
{
	t_hook	hook;

	if (init_movement_hooks(engine) == -1)
		return (-1);
	if (init_rotation_hooks(engine) == -1)
		return (-1);
	hook = create_mlx_hook(lock_camera, engine, KEY_ENTER, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(save_render, engine, KEY_P, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(speed_down, engine, MOUSE_WHEELDOWN, MOUSE);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(speed_up, engine, MOUSE_WHEELUP, MOUSE);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(change_render_mode, engine, KEY_M, PRESS);
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

static int	init_rotation_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(reset_roll_angle, engine, KEY_R, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(roll_left, engine, KEY_Q, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(roll_right, engine, KEY_E, HOLD);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(camera_mouse_hook, engine, 0, MOUSE_MOTION);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}
