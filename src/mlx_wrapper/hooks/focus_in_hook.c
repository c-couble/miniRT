/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus_in_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 05:05:44 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/24 23:41:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	focus_in_hook(t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	mlx->focused = 1;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == FOCUS_IN)
			hook->func(hook->param);
		++i;
	}
	return (0);
}
