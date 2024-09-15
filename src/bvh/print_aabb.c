/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aabb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:38:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 17:12:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bvh.h"
#include "vec3.h"

void	print_aabb(t_aabb *aabb, char *str)
{
	dprintf(2, "%s: \n", str);
	vec3_print(&aabb->min, "min");
	vec3_print(&aabb->max, "max");
}