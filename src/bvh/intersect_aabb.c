/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_aabb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:58:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 23:58:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "defines.h"
#include "bvh.h"
#include "util.h"

static int	get_tinterval_x(t_ray *r, t_aabb *aabb, double *t, double *t_end);
static int	get_tinterval_y(t_ray *r, t_aabb *aabb, double *t, double *t_end);
static int	get_tinterval_z(t_ray *r, t_aabb *aabb, double *t, double *t_end);

inline double	intersect_aabb(t_ray *ray, t_aabb *aabb)
{
	double	t_start;
	double	t_end;

	t_start = DBL_MIN;
	t_end = DBL_MAX;
	if (get_tinterval_x(ray, aabb, &t_start, &t_end) == -1)
		return (-1);
	if (get_tinterval_y(ray, aabb, &t_start, &t_end) == -1)
		return (-1);
	if (get_tinterval_z(ray, aabb, &t_start, &t_end) == -1)
		return (-1);
	if (t_start > t_end)
		return (-1);
	if (t_end < INACCURATE_ZERO)
		return (-1);
	if (t_start > INACCURATE_ZERO)
		return (t_start);
	return (t_end);
}

static int	get_tinterval_x(t_ray *r, t_aabb *aabb, double *t, double *t_end)
{
	double	t_1;
	double	t_2;

	if (r->ray.x == 0 && ((r->startpos.x < aabb->min.x)
			|| r->startpos.x > aabb->max.x))
		return (-1);
	t_1 = (aabb->min.x - r->startpos.x) * r->inv_x;
	t_2 = (aabb->max.x - r->startpos.x) * r->inv_x;
	if (t_1 > t_2)
		ft_dswap(&t_1, &t_2);
	if (t_1 > *t)
		*t = t_1;
	if (t_2 < *t_end)
		*t_end = t_2;
	return (0);
}

static int	get_tinterval_y(t_ray *r, t_aabb *aabb, double *t, double *t_end)
{
	double	t_1;
	double	t_2;

	if (r->ray.y == 0 && ((r->startpos.y < aabb->min.y)
			|| r->startpos.y > aabb->max.y))
		return (-1);
	t_1 = (aabb->min.y - r->startpos.y) * r->inv_y;
	t_2 = (aabb->max.y - r->startpos.y) * r->inv_y;
	if (t_1 > t_2)
		ft_dswap(&t_1, &t_2);
	if (t_1 > *t)
		*t = t_1;
	if (t_2 < *t_end)
		*t_end = t_2;
	return (0);
}

static int	get_tinterval_z(t_ray *r, t_aabb *aabb, double *t, double *t_end)
{
	double	t_1;
	double	t_2;

	if (r->ray.z == 0 && ((r->startpos.z < aabb->min.z)
			|| r->startpos.z > aabb->max.z))
		return (-1);
	t_1 = (aabb->min.z - r->startpos.z) * r->inv_z;
	t_2 = (aabb->max.z - r->startpos.z) * r->inv_z;
	if (t_1 > t_2)
		ft_dswap(&t_1, &t_2);
	if (t_1 > *t)
		*t = t_1;
	if (t_2 < *t_end)
		*t_end = t_2;
	return (0);
}
