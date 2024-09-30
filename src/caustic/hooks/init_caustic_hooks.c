/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:16:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 13:21:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "keyboard.h"

int	init_caustic_hooks(t_engine *engine)
{
	t_hook	hook;

	hook = create_mlx_hook(bandwith_decr, engine, KEY_NUM7, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(bandwith_incr, engine, KEY_NUM9, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(nearest_neighbour_decr, engine, KEY_NUM4, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(nearest_neighbour_incr, engine, KEY_NUM6, PRESS);
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
