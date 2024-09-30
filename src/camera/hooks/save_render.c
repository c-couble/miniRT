/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:41:21 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 10:48:53 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	save_render(t_engine *engine)
{
	engine->scene.camera.save = 1;
	engine->scene.camera.should_render = 1;
}
