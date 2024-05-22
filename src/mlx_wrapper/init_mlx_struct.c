/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 04:56:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/05/22 03:20:29 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "mlx.h"
#include "mlx_wrapper.h"
#include <stdlib.h>

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
	return (0);
}
