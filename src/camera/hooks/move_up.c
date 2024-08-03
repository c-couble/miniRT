/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:02:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 06:09:20 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"
#include "vec3.h"

void	move_up(t_engine *engine)
{
	t_camera	*cam;

	cam = &engine->scene.camera;
	if (cam->locked)
		return ;
	vec3_add(&cam->coordinates, &cam->up, &cam->coordinates);
	engine->scene.camera.should_render = 1;
}