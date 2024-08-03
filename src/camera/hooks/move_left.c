/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:02:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 06:09:30 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"
#include "vec3.h"

void	move_left(t_engine *engine)
{
	t_camera	*cam;

	cam = &engine->scene.camera;
	if (cam->locked)
		return ;
	vec3_subtract(&cam->coordinates, &cam->right, &cam->coordinates);
	engine->scene.camera.should_render = 1;
}