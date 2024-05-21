/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 04:56:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/05/21 04:39:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "mlx.h"
#include "mlx_wrapper.h"
#include <stdlib.h>

int	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (-1);
	mlx->mlx_window = mlx_new_window(mlx->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, WINDOW_NAME);
	if (mlx->mlx_window == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = NULL;
		return (-1);
	}
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx->img == NULL)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		mlx->mlx_window = NULL;
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = NULL;
		return (-1);
	}
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	return (0);
}
