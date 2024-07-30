/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_down_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 07:06:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 04:56:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	mouse_down_hook(int key, int x, int y, t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	(void)x;
	(void)y;
	i = 0;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == MOUSE && key == (int) hook->key)
		{
			hook->is_down = 1;
			if (hook->key == MOUSE_WHEELDOWN || hook->key == MOUSE_WHEELUP)
				hook->func(hook->param);
		}
		++i;
	}
	return (0);
}
