/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:12:21 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:37:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	loop_hook(t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == LOOP || hook->is_down)
			hook->func(hook->param);
		++i;
	}
	return (0);
}
