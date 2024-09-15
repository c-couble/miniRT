/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:10:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 11:13:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "keyboard.h"
#include "mlx_wrapper.h"
#include "object/camera.h"

void	increase_depth(t_engine *engine)
{
	engine->scene.camera.should_render = 1;
	engine->scene.bvh_depth += 1;
	engine->scene.bvh_depth %= engine->scene.bvh_m_depth + 1;
}

void	decrease_depth(t_engine *engine)
{
	engine->scene.camera.should_render = 1;
	engine->scene.bvh_depth -= 1;
	if (engine->scene.bvh_depth < 0)
		engine->scene.bvh_depth = engine->scene.bvh_m_depth + 0;
}

void	reset_depth(t_engine *engine)
{
	engine->scene.camera.should_render = 1;
	engine->scene.bvh_depth = engine->scene.bvh_m_depth + 1;
}

void	min_depth(t_engine *engine)
{
	engine->scene.camera.should_render = 1;
	engine->scene.bvh_depth = engine->scene.bvh_m_depth;
}

int	init_bvh_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(increase_depth, engine, KEY_UP, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(decrease_depth, engine, KEY_DOWN, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(min_depth, engine, KEY_LEFT, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(reset_depth, engine, KEY_RIGHT, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}
