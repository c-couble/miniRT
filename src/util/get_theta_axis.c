/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theta_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 03:53:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/01 04:58:29 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "util.h"
#include "vec3.h"

double	get_theta_axis(t_vec3 *axis, t_vec3 *rot_axis)
{
	t_vec3	z;
	double	theta;

	vec3_create(0, 0, 1, &z);
	if (double_equals(axis->z, 1) || double_equals(axis->z, -1))
		vec3_create(1, 0, 0, rot_axis);
	else
		vec3_normalize(vec3_cross(axis, &z, rot_axis));
	theta = vec3_dot(axis, &z)
		/ (vec3_get_norm(axis) * vec3_get_norm(&z));
	theta = acos(theta);
	return (theta);
}
