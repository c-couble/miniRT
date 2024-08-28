/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:47:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/21 05:13:23 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "scene.h"
#include "vector.h"

void	clear_engine(t_engine *engine)
{
	clear_scene(&engine->scene);
	clear_mlx_struct(&engine->mlx);
	clear_vector(&engine->objs_3d);
}
