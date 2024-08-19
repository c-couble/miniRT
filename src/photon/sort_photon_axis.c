/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_photon_axis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:50:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/19 15:26:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "photon.h"
#include "vector.h"
#include <stddef.h>
#include <unistd.h>

static size_t	array_partition(t_vector *phs, ssize_t start, ssize_t end, int axis);
static	int		compare_photon(t_photon *p1, t_photon *p2, int axis);
static	void	swap_photons(t_photon *p1, t_photon *p2);

void	sort_photons_axis(t_vector *point, ssize_t start, ssize_t end, int axis)
{
	ssize_t	pivot_index;

	if (start < end)
	{
		pivot_index = array_partition(point, start, end, axis);
		sort_photons_axis(point, start, pivot_index - 1, axis);
		sort_photons_axis(point, pivot_index + 1, end, axis);
	}
}

static	int compare_photon(t_photon *p1, t_photon *p2, int axis)
{
	const double	x = p1->pos.x;
	const double	y = p1->pos.y;
	const double	z = p1->pos.z;

	if (axis == 1)
		return (x - p2->pos.x);
	if (axis == 2)
		return (y - p2->pos.y);
	if (axis == 3)
		return (z - p2->pos.z);
	return (0);
}

static size_t	array_partition(t_vector *phs, ssize_t start, ssize_t end, int axis)
{
	t_photon	*pivot;
	ssize_t		i;
	ssize_t		j;
	t_photon	*photon;

	i = start;
	j = start;
	photon = at_vector(phs, end);
	pivot = photon;
	while (i < end)
	{
		photon = at_vector(phs, i);
		if (compare_photon(photon, pivot, axis) <= 0)
		{
			swap_photons(at_vector(phs, j), photon);
			++j;
		}
		++i;
	}
	swap_photons(at_vector(phs, j), at_vector(phs, end));
	return (j);
}

static	void	swap_photons(t_photon *p1, t_photon *p2)
{
	t_photon	tmp;

	tmp.pos = p1->pos;
	tmp.color = p1->color;
	p1->pos = p2->pos;
	p1->color = p2->color;
	p2->pos = tmp.pos;
	p2->color = tmp.color;
}
