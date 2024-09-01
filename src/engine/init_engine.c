/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/01 05:22:11 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "kdtree.h"
#include "mlx_wrapper.h"
#include "scene.h"
#include "photon.h"

static int	init_hooks(t_engine *engine);

int	init_engine(t_engine *engine, char *scene)
{
	if (init_scene(&engine->scene, scene) == -1)
		return (-1);
	if (init_photon_map(engine) == -1)
	{
		clear_scene(&engine->scene);
		return (-1);
	}
	if (init_mlx_struct(&engine->mlx) == -1)
	{
		clear_kdtree(engine->node);
		clear_scene(&engine->scene);
		return (-1);
	}
	if (init_hooks(engine) == -1)
	{
		clear_kdtree(engine->node);
		clear_scene(&engine->scene);
		clear_mlx_struct(&engine->mlx);
		return (-1);
	}
	return (0);
}

static int	init_hooks(t_engine *engine)
{
	t_hook	hook;

	if (init_camera_hooks(engine) == -1)
		return (-1);
	hook = create_mlx_hook(engine_focus_in, engine, 0, FOCUS_IN);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(quit_engine, engine, KEY_ESCAPE, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(quit_engine, engine, 0, DESTROY);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	return (0);
}
