/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_roll_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 04:07:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 14:10:39 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

void	reset_roll_angle(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	create_camera_vectors(&engine->scene.camera);
	engine->scene.camera.should_render = 1;
}
