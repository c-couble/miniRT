/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_render_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:46:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 04:51:48 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

void	change_render_mode(t_engine *engine)
{
	++engine->scene.camera.render_type;
	if (engine->scene.camera.render_type > UV_MAP)
		engine->scene.camera.render_type = CLASSIC;
	engine->scene.camera.should_render = 1;
}
