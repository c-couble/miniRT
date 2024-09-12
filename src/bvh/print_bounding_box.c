/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d_aabb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:42:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 17:43:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "ft_io.h"
#include "vec3.h"

void	print_bounding_box(t_b_box *b_box)
{
	ft_dprintf(2, "bounding_box\n");
	vec3_print(&b_box->top[0], "T R L");
	vec3_print(&b_box->top[1], "T F L");
	vec3_print(&b_box->top[2], "T F R");
	vec3_print(&b_box->top[3], "T R R");
	vec3_print(&b_box->bottom[0], "D R L");
	vec3_print(&b_box->bottom[1], "D R R");
	vec3_print(&b_box->bottom[2], "D F R");
	vec3_print(&b_box->bottom[3], "D F L");
}
