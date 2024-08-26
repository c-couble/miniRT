/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 03:57:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/24 04:57:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	mouse_motion_hook(int x, int y, t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	mlx->x = x;
	mlx->y = y;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == MOUSE_MOTION)
			hook->func(hook->param);
		++i;
	}
	mlx->old_x = mlx->x;
	mlx->old_y = mlx->y;
	return (0);
}
