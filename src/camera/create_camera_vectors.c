/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 04:11:14 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 05:37:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/camera.h"
#include "util.h"
#include "vec3.h"

void	create_camera_vectors(t_camera *cam)
{
	if (double_equals(cam->front.z, 1) || double_equals(cam->front.z, -1))
		vec3_create(0, -1, 0, &cam->front);
	vec3_create(0, 0, 1, &cam->up);
	vec3_cross_product(&cam->front, &cam->up, &cam->right);
	vec3_normalize(&cam->right);
	vec3_cross_product(&cam->right, &cam->front, &cam->up);
}
