/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:16:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 23:18:50 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	incr(t_engine *engine)
{
	engine->caustic.bandwidth += 0.05;
	engine->scene.camera.should_render = 1;
}

void	decr(t_engine *engine)
{
	engine->caustic.bandwidth -= 0.05;
	engine->scene.camera.should_render = 1;
}

void	i(t_engine *engine)
{
	engine->caustic.nn += 1;
	engine->scene.camera.should_render = 1;
}

void	b(t_engine *engine)
{
	if (engine->caustic.nn > 0)
		engine->caustic.nn -= 1;
	engine->scene.camera.should_render = 1;
}

int	init_caustic_hooks(t_engine *engine)
{
	t_hook	hook;

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
