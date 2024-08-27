/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:11:09 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:37:15 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mlx_wrapper.h"

int	key_down_hook(int key, t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == PRESS && key == (int) hook->key)
			hook->func(hook->param);
		if (hook->type == HOLD && key == (int) hook->key)
			hook->is_down = 1;
		++i;
	}
	return (0);
}
