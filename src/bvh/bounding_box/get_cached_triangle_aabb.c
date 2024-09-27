/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cached_triangle_aabb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:51:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 06:28:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bounding_box.h"
#include "ft_math.h"
#include "object/triangle.h"

void	get_cached_triangle_aabb(t_cached_triangle *triangle, t_aabb *aabb)
{
	int	i;

	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &aabb->max);
	i = 0;
	while (i < 3)
	{
		aabb->min.x = ft_dmin(aabb->min.x, triangle->points[i].x);
		aabb->min.y = ft_dmin(aabb->min.y, triangle->points[i].y);
		aabb->min.z = ft_dmin(aabb->min.z, triangle->points[i].z);
		aabb->max.x = ft_dmax(aabb->max.x, triangle->points[i].x);
		aabb->max.y = ft_dmax(aabb->max.y, triangle->points[i].y);
		aabb->max.z = ft_dmax(aabb->max.z, triangle->points[i].z);
		++i;
	}
}
