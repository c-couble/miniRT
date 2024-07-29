/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:11:22 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 04:12:53 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

int	destroy_hook(t_mlx *mlx)
{
	t_hook		*hook;
	size_t		i;

	i = 0;
	while (i < mlx->hooks.size)
	{
		hook = at_vector(&mlx->hooks, i);
		if (hook->type == DESTROY)
			hook->func(hook->param);
		++i;
	}
	return (0);
}
