/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/02 05:45:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "keyboard.h"
#include "mlx_wrapper.h"
#include "obj_3d.h"
#include "obj_mtl.h"
#include "scene.h"
#include "texture.h"
#include "vector.h"

static int	init_hooks(t_engine *engine);

int	init_engine(t_engine *engine, char *scene)
{
	init_vector(&engine->objs_3d, sizeof(t_obj_3d));
	init_vector(&engine->obj_mtls, sizeof(t_obj_mtl));
	init_vector(&engine->textures, sizeof(t_texture));
	if (init_scene(engine, &engine->scene, scene) == -1)
		return (-1);
	if (init_mlx_struct(&engine->mlx) == -1)
	{
		clear_scene(&engine->scene);
		return (-1);
	}
	if (init_hooks(engine) == -1)
	{
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
