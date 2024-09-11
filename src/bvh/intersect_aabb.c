/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_aabb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:58:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 21:57:39 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "bvh.h"
#include "util.h"
#include <float.h>
#include <stdio.h>

int	get_tinterval_axis(t_ray *ray, t_aabb *aabb, double *t_start, double *t_end, int axis);

double		intersect_aabb(t_ray *ray, t_aabb *aabb)
{
	double	t_start;
	double	t_end;

	t_start = DBL_MIN;
	t_end	= DBL_MAX; 
	if (get_tinterval_axis(ray, aabb, &t_start, &t_end, X) == -1)
		return (-1);
	if (get_tinterval_axis(ray, aabb, &t_start, &t_end, Y) == -1)
		return (-1);
	if (get_tinterval_axis(ray, aabb, &t_start, &t_end, Z) == -1)
		return (-1);
//	printf("t_s = %lf t_end = %lf\n", t_start, t_end);
	if (t_start > t_end)
		return (-1);
	if (t_end < INACCURATE_ZERO)
		return (-1);
	if (t_start > INACCURATE_ZERO)
		return (t_start);
	return (t_end);
}

int	get_tinterval_axis(t_ray *ray, t_aabb *aabb, double *t_start, double *t_end, int axis)
{
	double	t_1;
	double	t_2;

	if (get_axis(&ray->ray, axis) == 0 
		&& (get_axis(&ray->startpos, axis) < get_axis(&aabb->min, axis)
		|| get_axis(&ray->startpos, axis) > get_axis(&aabb->max, axis)))
		return (-1);
	t_1 = (get_axis(&aabb->min, axis) - get_axis(&ray->startpos, axis))
		/ get_axis(&ray->ray, axis);
	t_2 = (get_axis(&aabb->max, axis) - get_axis(&ray->startpos, axis))
		/ get_axis(&ray->ray, axis);
	if (t_1 > t_2)
		ft_dswap(&t_1, &t_2);
	if (t_1 > *t_start)
		*t_start = t_1;
	if (t_2 < *t_end)
		*t_end = t_2;
	return (0);
}
