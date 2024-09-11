/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d_aabb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:15:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 17:35:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "ft_io.h"
#include "vec3.h"

void	print_3d_aabb(t_3d_aabb *aabb)
{
	ft_dprintf(2, "3d_aabb\n");
	vec3_print(&aabb->cube[0], "F U L");
	vec3_print(&aabb->cube[1], "F U R");
	vec3_print(&aabb->cube[2], "F D R");
	vec3_print(&aabb->cube[3], "F D L");
	vec3_print(&aabb->cube[4], "R U L");
	vec3_print(&aabb->cube[5], "R U R");
	vec3_print(&aabb->cube[6], "R D R");
	vec3_print(&aabb->cube[7], "R D L");
}
