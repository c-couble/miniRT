/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/05/21 04:40:19 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx_wrapper.h"
#include "scene.h"

int	init_engine(t_engine *engine, char *scene)
{
	if (init_scene(&engine->scene, scene) == -1)
		return (-1);
	if (init_mlx_struct(&engine->mlx) == -1)
		return (-1);
	return (0);
}
