/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bounding_box.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:42:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:53:40 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "ft_io.h"
#include "vec3.h"

void	print_bounding_box(t_bbox *bbox)
{
	ft_dprintf(2, "bounding_box\n");
	vec3_print(&bbox->top[0], "T R L");
	vec3_print(&bbox->top[1], "T F L");
	vec3_print(&bbox->top[2], "T F R");
	vec3_print(&bbox->top[3], "T R R");
	vec3_print(&bbox->bottom[0], "D R L");
	vec3_print(&bbox->bottom[1], "D F L");
	vec3_print(&bbox->bottom[2], "D F R");
	vec3_print(&bbox->bottom[3], "D R R");
}
