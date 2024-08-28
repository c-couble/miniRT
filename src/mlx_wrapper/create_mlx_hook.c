/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 04:22:35 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 04:24:31 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

t_hook	create_mlx_hook(void (*f)(), void *param, t_key key, t_hooktype type)
{
	t_hook	hook;

	hook.func = f;
	hook.param = param;
	hook.key = key;
	hook.type = type;
	hook.is_down = 0;
	return (hook);
}
