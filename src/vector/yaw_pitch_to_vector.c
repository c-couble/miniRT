/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaw_pitch_to_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 05:27:44 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/23 06:25:16 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <stdio.h>
#include <math.h>

void	yaw_pitch_to_vector(t_vector3d *vector, double yaw, double pitch)
{
	const double	cos_pitch = cos(pitch);

	vector->x = cos(yaw) * cos_pitch;
	vector->y = sin(yaw) * cos_pitch;
	vector->z = sin(pitch);
	//printf("reverted %lf;%lf to %lf %lf %lf\n", yaw, pitch, vector->x,
//		vector->y, vector->z);
}
