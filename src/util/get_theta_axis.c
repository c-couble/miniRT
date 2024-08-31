/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theta_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 03:53:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/31 03:53:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"

double	get_theta_axis(t_vec3 *axis, t_vec3 *rot_axis)
{
	t_vec3	z;
	double	theta;

	z.x = 0;
	z.y = 0;
	z.z = 1;
	vec3_cross(axis, &z, rot_axis);
	vec3_normalize(&z);
	theta = vec3_dot(axis, &z)
		/ (vec3_get_norm(axis) * vec3_get_norm(&z));
	theta = acos(theta);
	if (rot_axis->x == 0 && rot_axis->y == 0 && rot_axis->z == 0)
	{
		rot_axis->x = 1;
		rot_axis->y = 0;
		rot_axis->z = 0;
	}
	return (theta);
}
