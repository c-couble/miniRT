/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bvh_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:10:26 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 23:20:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
	return (0);
}
