/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_render_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:46:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 14:09:05 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

void	change_render_mode(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	++engine->scene.camera.render_type;
	if (engine->scene.camera.render_type > BOUNDING_BOX)
		engine->scene.camera.render_type = CLASSIC;
	engine->scene.camera.should_render = 1;
}
