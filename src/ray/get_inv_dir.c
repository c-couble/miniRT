/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inv_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:34:36 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 20:18:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ray.h"

static double	safe_div(double divider);

void	get_inv_dir(t_ray *ray)
{
	ray->inv_x = safe_div(ray->ray.x);
	ray->inv_y = safe_div(ray->ray.y);
	ray->inv_z = safe_div(ray->ray.z);
}

static double	safe_div(double divider)
{
	if (divider == 0)
		return (DBL_MAX);
	return (1 / divider);
}
