/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mesh_aabb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:49:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 00:24:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bounding_box.h"
#include "ft_math.h"
#include "object/mesh.h"

void	get_mesh_aabb(t_mesh *mesh, t_aabb *aabb)
{
	size_t	i;
	t_aabb	tmp;

	i = 0;
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &aabb->max);
	while (i < mesh->triangles)
	{
		get_cached_triangle_aabb(&mesh->cache[i], &tmp);
		aabb->min.x = ft_dmin(aabb->min.x, tmp.min.x);
		aabb->min.y = ft_dmin(aabb->min.y, tmp.min.y);
		aabb->min.z = ft_dmin(aabb->min.z, tmp.min.z);
		aabb->max.x = ft_dmax(aabb->max.x, tmp.max.x);
		aabb->max.y = ft_dmax(aabb->max.y, tmp.max.y);
		aabb->max.z = ft_dmax(aabb->max.z, tmp.max.z);
		++i;
	}
	get_aabb_center(aabb);
}
