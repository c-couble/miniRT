/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bbox_from_aabb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:03:21 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 15:31:53 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

static	void	get_bb_top_face(t_vec3 top[4], t_aabb *aabb);
static	void	get_bb_bottom_face(t_vec3 bottom[4], t_aabb *aabb);

void	get_bbox_from_aabb(t_aabb *aabb, t_bbox *bbox)
{
	get_bb_top_face(bbox->top, aabb);
	get_bb_bottom_face(bbox->bottom, aabb);
}

static	void	get_bb_top_face(t_vec3 top[4], t_aabb *aabb)
{
	vec3_create(aabb->min.x, aabb->min.y, aabb->max.z, &top[0]);
	vec3_create(aabb->min.x, aabb->max.y, aabb->max.z, &top[1]);
	vec3_create(aabb->max.x, aabb->max.y, aabb->max.z, &top[2]);
	vec3_create(aabb->max.x, aabb->min.y, aabb->max.z, &top[3]);
}

static	void	get_bb_bottom_face(t_vec3 bottom[4], t_aabb *aabb)
{
	vec3_create(aabb->min.x, aabb->min.y, aabb->min.z, &bottom[0]);
	vec3_create(aabb->min.x, aabb->max.y, aabb->min.z, &bottom[1]);
	vec3_create(aabb->max.x, aabb->max.y, aabb->min.z, &bottom[2]);
	vec3_create(aabb->max.x, aabb->min.y, aabb->min.z, &bottom[3]);
}
