/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:12:21 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 05:01:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "mlx.h"
#include <stdio.h>

int	loop_hook(t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	mlx_mouse_get_pos(mlx->mlx, mlx->mlx_window, &mlx->x, &mlx->y);
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == LOOP || hook->is_down)
			hook->func(hook->param);
		++i;
	}
	mlx->old_x = mlx->x;
	mlx->old_y = mlx->y;
	return (0);
}
