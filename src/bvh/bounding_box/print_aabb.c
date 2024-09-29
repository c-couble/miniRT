/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aabb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:38:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 01:25:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bounding_box.h"
#include "vec3.h"

void	print_aabb(t_aabb *aabb, char *str)
{
	dprintf(2, "%s: \n", str);
	vec3_print(&aabb->min, "min");
	vec3_print(&aabb->max, "max");
	vec3_print(&aabb->center, "center");
}
