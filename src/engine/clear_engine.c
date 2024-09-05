/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:47:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/05 07:53:07 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "scene.h"
#include "texture.h"
#include "vector.h"

void	clear_engine(t_engine *engine)
{
	clear_scene(&engine->scene);
	clear_mlx_struct(&engine->mlx);
	clear_textures(&engine->textures);
	clear_vector(&engine->objs_3d);
}
