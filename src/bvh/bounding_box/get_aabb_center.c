/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aabb_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:17:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 01:11:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "vec3.h"

void	get_aabb_center(t_aabb *aabb)
{
	vec3_subtract(&aabb->max, &aabb->min, &aabb->center);
	vec3_scale(&aabb->center, 0.5);
	vec3_add(&aabb->min, &aabb->center, &aabb->center);
}
