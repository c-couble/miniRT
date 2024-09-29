/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:16:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/29 22:52:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	bw_incr(t_engine *engine);
static void	bw_decr(t_engine *engine);
static void	nn_incr(t_engine *engine);
static void	nn_decr(t_engine *engine);

int	init_caustic_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(bw_decr, engine, KEY_F, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(bw_incr, engine, KEY_G, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(nn_decr, engine, KEY_H, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(nn_incr, engine, KEY_J, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}

static void	bw_incr(t_engine *engine)
{
	engine->scene.caustic.bandwidth += 0.01;
	engine->scene.camera.should_render = 1;
	update_caustic_aabb(&engine->scene, 1);
}

static void	bw_decr(t_engine *engine)
{
	if (engine->scene.caustic.bandwidth > 0.01)
	{
		engine->scene.caustic.bandwidth -= 0.01;
		update_caustic_aabb(&engine->scene, 0);
	}
	engine->scene.camera.should_render = 1;
}

static void	nn_incr(t_engine *engine)
{
	if (engine->scene.caustic.nn < (int)engine->scene.caustic.knn.max_size - 1)
		engine->scene.caustic.nn += 1;
	engine->scene.camera.should_render = 1;
}

static void	nn_decr(t_engine *engine)
{
	if (engine->scene.caustic.nn > 0)
		engine->scene.caustic.nn -= 1;
	engine->scene.camera.should_render = 1;
}
