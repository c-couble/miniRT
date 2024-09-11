/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_checkerboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:40:29 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 08:48:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "checkerboard.h"
#include "object.h"

void	apply_checkerboard(t_ray *ray, t_object *obj)
{
	const t_checkerboard	checker = obj->optional_data.checker;
	double					x;
	double					y;

	if (checker.y_size || checker.x_size)
	{
		x = floor(ray->data.u * checker.x_size + 0.5);
		y = floor(ray->data.v * checker.y_size + 0.5);
		if (fmod(x + y, 2.) == 0.0)
			ray->data.color.color = checker.x_color.color;
		else
			ray->data.color.color = checker.y_color.color;
	}
}
