/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaw_pitch_to_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 05:27:44 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:43:42 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

void	yaw_pitch_to_vector(t_vec3 *vector, double yaw, double pitch)
{
	const double	cos_pitch = cos(pitch);

	vector->x = cos(yaw) * cos_pitch;
	vector->y = sin(yaw) * cos_pitch;
	vector->z = sin(pitch);
}
