/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus_out_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 05:06:56 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/24 05:34:38 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_wrapper.h"

int	focus_out_hook(t_mlx *mlx)
{
	mlx->focused = 0;
	mlx_mouse_show(mlx->mlx, mlx->mlx_window);
	return (0);
}
