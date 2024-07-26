/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/26 04:36:25 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx_wrapper.h"
#include "obj_3d.h"
#include "scene.h"
#include "vector.h"

int	init_engine(t_engine *engine, char *scene)
{
	init_vector(&engine->objs_3d, sizeof(t_obj_3d));
	if (init_scene(engine, &engine->scene, scene) == -1)
		return (-1);
	if (init_mlx_struct(&engine->mlx) == -1)
		return (-1);
	return (0);
}
