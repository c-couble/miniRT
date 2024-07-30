/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:11:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 04:13:07 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	key_up_hook(int key, t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == HOLD && key == (int) hook->key)
			hook->is_down = 0;
		++i;
	}
	return (0);
}
