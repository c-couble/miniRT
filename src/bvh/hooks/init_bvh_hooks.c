/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:10:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/24 17:15:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	incr(t_engine *engine)
{
	engine->bandwidth += 0.05;
	engine->scene.camera.should_render = 1;
}

void	decr(t_engine *engine)
{
	engine->bandwidth -= 0.05;
	engine->scene.camera.should_render = 1;
}

void	i(t_engine *engine)
{
	engine->nn += 1;
	engine->scene.camera.should_render = 1;
}

void	b(t_engine *engine)
{
	if (engine->nn > 0)
		engine->nn -= 1;
	engine->scene.camera.should_render = 1;
}

int	init_bvh_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(increase_single_layer, engine, KEY_UP, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(decrease_single_layer, engine, KEY_DOWN, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(increase_full_layer, engine, KEY_RIGHT, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(decrease_full_layer, engine, KEY_LEFT, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(change_bvh_mode, engine, KEY_B, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(decr, engine, KEY_F, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(incr, engine, KEY_G, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(b, engine, KEY_H, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(i, engine, KEY_J, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}
