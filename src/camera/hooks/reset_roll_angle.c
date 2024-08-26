/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_roll_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 04:07:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 05:39:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object/camera.h"

void	reset_roll_angle(t_engine *engine)
{
	create_camera_vectors(&engine->scene.camera);
	engine->scene.camera.should_render = 1;
}
