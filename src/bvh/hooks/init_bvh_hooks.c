/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:10:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 23:45:22 by lespenel         ###   ########.fr       */
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

int	init_bvh_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(increase_depth_manual, engine, KEY_UP, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(decrease_depth_manual, engine, KEY_DOWN, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(increase_depth_persistent, engine, KEY_LEFT, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(decrease_depth_persistent, engine, KEY_RIGHT, PRESS);
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
	return (0);
}
