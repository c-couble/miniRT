/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/18 14:45:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx_wrapper.h"
#include "scene.h"
#include "photon.h"

static int	init_hooks(t_engine *engine);

int	init_engine(t_engine *engine, char *scene)
{
	if (init_scene(&engine->scene, scene) == -1)
		return (-1);
	if (init_photon_map(engine) == -1)
		return (-1);
//	return (-1);
	if (init_mlx_struct(&engine->mlx) == -1)
		return (-1);
	if (init_hooks(engine) == -1)
		return (-1);
	return (0);
}

static int	init_hooks(t_engine *engine)
{
	if (init_camera_hooks(engine) == -1)
		return (-1);
	return (0);
}
