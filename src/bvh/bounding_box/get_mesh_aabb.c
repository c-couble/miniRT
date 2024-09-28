/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mesh_aabb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:49:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 01:43:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bounding_box.h"
#include "ft_math.h"
#include "object/mesh.h"

static void	set_mesh_tri_aabb(t_mesh *mesh);

void	get_mesh_aabb(t_mesh *mesh, t_aabb *aabb)
{
	size_t	i;

	i = 0;
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &aabb->max);
	set_mesh_tri_aabb(mesh);
	while (i < mesh->triangles)
	{
		aabb->min.x = ft_dmin(aabb->min.x, mesh->cache[i].aabb.min.x);
		aabb->min.y = ft_dmin(aabb->min.y, mesh->cache[i].aabb.min.y);
		aabb->min.z = ft_dmin(aabb->min.z, mesh->cache[i].aabb.min.z);
		aabb->max.x = ft_dmax(aabb->max.x, mesh->cache[i].aabb.max.x);
		aabb->max.y = ft_dmax(aabb->max.y, mesh->cache[i].aabb.max.y);
		aabb->max.z = ft_dmax(aabb->max.z, mesh->cache[i].aabb.max.z);
		++i;
	}
	get_aabb_center(aabb);
}

static void	set_mesh_tri_aabb(t_mesh *mesh)
{
	size_t	i;

	i = 0;
	while (i < mesh->triangles)
	{
		get_cached_triangle_aabb(&mesh->cache[i], &mesh->cache[i].aabb);
		++i;
	}
}
