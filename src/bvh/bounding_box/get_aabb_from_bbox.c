/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aabb_from_bbox.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:50:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "bounding_box.h"
#include "ft_math.h"
#include "vec3.h"

static void	get_aabb_from_face(t_vec3 *face, t_aabb *aabb);

void	get_aabb_from_bbox(t_bbox *bbobx, t_aabb *aabb)
{
	vec3_create(DBL_MAX, DBL_MAX, DBL_MAX, &aabb->min);
	vec3_create(-DBL_MAX, -DBL_MAX, -DBL_MAX, &aabb->max);
	get_aabb_from_face(bbobx->top, aabb);
	get_aabb_from_face(bbobx->bottom, aabb);
}

static	void	get_aabb_from_face(t_vec3 *face, t_aabb *aabb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		aabb->min.x = ft_dmin(face[i].x, aabb->min.x);
		aabb->min.y = ft_dmin(face[i].y, aabb->min.y);
		aabb->min.z = ft_dmin(face[i].z, aabb->min.z);
		aabb->max.x = ft_dmax(face[i].x, aabb->max.x);
		aabb->max.y = ft_dmax(face[i].y, aabb->max.y);
		aabb->max.z = ft_dmax(face[i].z, aabb->max.z);
		++i;
	}
}
