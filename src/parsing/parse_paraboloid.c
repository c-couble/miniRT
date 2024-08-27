/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:03:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/07 00:05:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"
#include "float.h"
#include <math.h>

static double	get_theta_axis(t_vec3 *axis, t_vec3 *rot_axis);

int	parse_paraboloid(t_object_data *data)
{
	char	*arg;

	if (parse_vector3d(&data->paraboloid.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->paraboloid.axis) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->paraboloid.ray_coef, arg, 0, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->paraboloid.height, arg, 0, DBL_MAX) == -1)
		return (-1);
	if (parse_color(&data->paraboloid.color) == -1)
		return (-1);
	data->paraboloid.theta = get_theta_axis(&data->paraboloid.axis,
			&data->paraboloid.rot_axis);
	return (0);
}

static double	get_theta_axis(t_vec3 *axis, t_vec3 *rot_axis)
{
	t_vec3	z;
	double	theta;

	z.x = 0;
	z.y = 0;
	z.z = 1;
	vec3_cross_product(axis, &z, rot_axis);
	vec3_normalize(&z);
	theta = vec3_dot_product(axis, &z)
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
