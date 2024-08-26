/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:19:35 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 02:59:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/camera.h"
#include "vec3.h"

void	move_camera(t_camera *camera, t_vec3 *axis, int invert)
{
	t_vec3	tmp;

	tmp = *axis;
	vec3_scale(&tmp, camera->speed * (camera->last_frame_time / 1000.));
	if (invert)
		vec3_subtract(&camera->coordinates, &tmp, &camera->coordinates);
	else
		vec3_add(&camera->coordinates, &tmp, &camera->coordinates);
	camera->should_render = 1;
}
