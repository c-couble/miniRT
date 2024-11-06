/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 01:55:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/11/04 02:05:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "engine.h"
#include "object/camera.h"

void	print_camera_pos(t_engine *engine)
{
	printf("%lf,%lf,%lf  pos\n", engine->scene.camera.coordinates.x,
		engine->scene.camera.coordinates.y, engine->scene.camera.coordinates.z);
	printf("%lf,%lf,%lf  lookat\n", engine->scene.camera.front.x,
		engine->scene.camera.front.y, engine->scene.camera.front.z);
	printf("caustic bandwith: %lf\n", engine->scene.caustic.bandwidth);
	printf("caustic nn: %ld\n", engine->scene.caustic.nn_nb);
	printf("caustic intensity scalar: %ld\n",
		engine->scene.caustic.intensity_scalar);
}
