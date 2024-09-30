/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:16:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:53:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "engine.h"
#include "keyboard.h"

static void	bw_incr(t_engine *engine);
static void	bw_decr(t_engine *engine);
static void	nn_incr(t_engine *engine);
static void	nn_decr(t_engine *engine);
static void	estimation_incr(t_engine *engine);
static void	estimation_decr(t_engine *engine);

int	init_caustic_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(bw_decr, engine, KEY_NUM7, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(bw_incr, engine, KEY_NUM9, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(nn_decr, engine, KEY_NUM4, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(nn_incr, engine, KEY_NUM6, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(estimation_decr, engine, KEY_NUM1, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(estimation_incr, engine, KEY_NUM3, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}

static void	estimation_incr(t_engine *engine)
{
	if (engine->scene.caustic.intensity_scalar < 10000)
	{
		engine->scene.caustic.intensity_scalar += 1;
		engine->scene.camera.should_render = 1;
	}
}

static void	estimation_decr(t_engine *engine)
{
	if (engine->scene.caustic.intensity_scalar > 0)
	{
		engine->scene.caustic.intensity_scalar -= 1;
		engine->scene.camera.should_render = 1;
	}
}

static void	bw_incr(t_engine *engine)
{
	engine->scene.caustic.bandwidth += 0.01;
	engine->scene.camera.should_render = 1;
	update_caustic_aabb(&engine->scene);
}

static void	bw_decr(t_engine *engine)
{
	engine->scene.caustic.bandwidth -= 0.01;
	engine->scene.camera.should_render = 1;
}

static void	nn_incr(t_engine *engine)
{
	if (engine->scene.caustic.nn_nb < engine->scene.caustic.knn_max_size - 1)
	{
		engine->scene.caustic.nn_nb += 1;
		engine->scene.camera.should_render = 1;
	}
}

static void	nn_decr(t_engine *engine)
{
	if (engine->scene.caustic.nn_nb > 0)
	{
		engine->scene.caustic.nn_nb -= 1;
		engine->scene.camera.should_render = 1;
	}
}
