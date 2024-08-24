/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 04:56:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/24 05:34:00 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "mlx.h"
#include "mlx_wrapper.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

static void	init_intern_hooks(t_mlx *mlx);

int	init_mlx_struct(t_mlx *mlx)
{
	mlx->height = SCREEN_HEIGHT;
	mlx->width = SCREEN_WIDTH;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (-1);
	mlx->mlx_window = mlx_new_window(mlx->mlx, mlx->width,
			mlx->height, WINDOW_NAME);
	if (mlx->mlx_window == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		return (-1);
	}
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx->img == NULL)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		return (-1);
	}
	mlx->addr = (t_color *) mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	init_intern_hooks(mlx);
	mlx->focused = 1;
	return (0);
}

static void	init_intern_hooks(t_mlx *mlx)
{
	init_vector(&mlx->hooks, sizeof(t_hook));
	mlx_hook(mlx->mlx_window, 2, 1L << 0, key_down_hook, mlx);
	mlx_hook(mlx->mlx_window, 3, 1L << 1, key_up_hook, mlx);
	mlx_hook(mlx->mlx_window, 4, 1L << 2, mouse_down_hook, mlx);
	mlx_hook(mlx->mlx_window, 5, 1L << 3, mouse_up_hook, mlx);
	mlx_hook(mlx->mlx_window, 6, 1L << 6, mouse_motion_hook, mlx);
	mlx_hook(mlx->mlx_window, 9, FocusChangeMask, focus_in_hook, mlx);
	mlx_hook(mlx->mlx_window, 10, FocusChangeMask, focus_out_hook, mlx);
	mlx_hook(mlx->mlx_window, 17, 1L << 0, destroy_hook, mlx);
	mlx_loop_hook(mlx->mlx, loop_hook, mlx);
	mlx_mouse_get_pos(mlx->mlx, mlx->mlx_window, &mlx->old_x, &mlx->old_y);
}
