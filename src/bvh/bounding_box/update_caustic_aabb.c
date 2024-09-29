/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_caustic_aabb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 03:06:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/29 23:41:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "caustic.h"
#include "defines.h"
#include "scene.h"
#include "vector.h"

static void	update_aabb_incr(t_aabb *aabb, double bandwith);

void	update_caustic_aabb(t_scene *scene)
{
	size_t			i;
	t_caustic_map	*map;

	i = 0;
	map = scene->caustic.caustic_maps.array;
	while (i < scene->caustic.caustic_maps.size)
	{
		update_aabb_incr(&map[i].aabb, scene->caustic.bandwidth);
		++i;
	}
}

static void	update_aabb_incr(t_aabb *aabb, double bandwith)
{
	const double	incr = CA_BBOX_SCALING * sqrt(bandwith);

	aabb->min.x -= incr;
	aabb->min.y -= incr;
	aabb->min.z -= incr;
	aabb->max.x += incr;
	aabb->max.y += incr;
	aabb->max.z += incr;
}
