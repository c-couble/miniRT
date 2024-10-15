/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:03:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/10/15 09:54:28 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <math.h>
#include "engine.h"
#include "ft_string.h"
#include "util.h"
#include "object.h"
#include "object/parse_util.h"

static void	fill_properties(t_paraboloid *para);

int	parse_paraboloid(t_engine *engine, t_object_data *data)
{
	char			*arg;

	(void) engine;
	if (parse_vector3d(&data->paraboloid.pos, -DBL_MAX, DBL_MAX) == -1)
		return (-1);
	if (parse_normalized_vector3d(&data->paraboloid.axis) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->paraboloid.radius, arg, 0, DBL_MAX) == -1)
		return (-1);
	data->paraboloid.radiussq = powl(data->paraboloid.radius, 2);
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->paraboloid.height, arg, 0, DBL_MAX) == -1)
		return (-1);
	arg = ft_strtok(NULL, " \t");
	if (parse_int(&data->paraboloid.disk, arg, 0, 1) == -1)
		return (-1);
	if (parse_color(&data->paraboloid.color) == -1)
		return (-1);
	fill_properties(&data->paraboloid);
	return (0);
}

static void	fill_properties(t_paraboloid *para)
{
	t_vec3	tmp;

	para->theta = get_theta_axis(&para->axis, &para->rot_axis);
	if (para->radius < 0.01)
		para->radius_coef = 0;
	para->radius_coef = para->height / (para->radius * para->radius);
	tmp = para->axis;
	vec3_scale(&tmp, para->height / 2);
	vec3_add(&para->pos, &tmp, &para->center);
}
