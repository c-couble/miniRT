/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustic_aabb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 05:30:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 19:42:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bounding_box.h"
#include "ft_math.h"
#include "photon.h"
#include "vector.h"

void	get_caustic_aabb(t_vector *photons, t_aabb *aabb)
{
	size_t		i;
	t_photon	*photon;

	i = 0;
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &aabb->max);
	photon = photons->array;
	while (i < photons->size)
	{
		aabb->min.x = ft_dmin(aabb->min.x, photon[i].pos.x);
		aabb->min.y = ft_dmin(aabb->min.y, photon[i].pos.y);
		aabb->min.z = ft_dmin(aabb->min.z, photon[i].pos.z);
		aabb->max.x = ft_dmax(aabb->max.x, photon[i].pos.x);
		aabb->max.y = ft_dmax(aabb->max.y, photon[i].pos.y);
		aabb->max.z = ft_dmax(aabb->max.z, photon[i].pos.z);
		++i;
	}
	aabb->min.x -= 1;
	aabb->min.y -= 1;
	aabb->min.z -= 1;
	aabb->max.x += 1;
	aabb->max.y += 1;
	aabb->max.z += 1;
}
