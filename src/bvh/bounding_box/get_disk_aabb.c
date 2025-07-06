/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disk_aabb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:52:03 by lespenel          #+#    #+#             */
/*   Updated: 2025/07/06 23:39:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "object/disk.h"

void	get_disk_aabb(t_disk *disk, t_aabb *aabb)
{
	aabb->min.x = disk->pos.x - disk->radius;
	aabb->min.y = disk->pos.y - disk->radius;
	aabb->min.z = disk->pos.z - disk->radius;
	aabb->max.x = disk->pos.x + disk->radius;
	aabb->max.y = disk->pos.y + disk->radius;
	aabb->max.z = disk->pos.z + disk->radius;
	aabb->center = disk->pos;
}
