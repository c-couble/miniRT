/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:47:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 06:26:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "engine.h"
#include "scene.h"
#include "texture.h"
#include "vector.h"

void	clear_engine(t_engine *engine)
{
	clear_caustic_maps(&engine->caustic_maps);
	clear_scene(&engine->scene);
	clear_mlx_struct(&engine->mlx);
	clear_textures(&engine->textures);
	clear_vector(&engine->objs_3d);
}
