/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:47:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:40:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine.h"
#include "obj_3d.h"
#include "scene.h"
#include "texture.h"

void	clear_engine(t_engine *engine)
{
	clear_threads(engine, engine->thread_count);
	clear_scene(&engine->scene);
	clear_mlx_struct(&engine->mlx);
	clear_textures(&engine->textures);
	clear_objs_3d(&engine->objs_3d);
	clear_mtls(&engine->obj_mtls);
	if (engine->render_width != 0 && engine->render_height != 0)
		free(engine->render_data);
}
