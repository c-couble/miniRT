/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_photon_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:42:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/18 21:43:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "photon.h"
#include "util.h"
#include <stdio.h>

void	print_photon_map(t_engine *engine)
{
	size_t		i;
	t_photon	*curr;
	
	i = 0;
	while (i < engine->photon_map.size)
	{
		curr = at_vector(&engine->photon_map, i);
		print_vec3(&curr->pos, "p_ray");
		printf("color r = %d, g = %d, b = %d\n", curr->color.rgb.r, curr->color.rgb.b,
		 curr->color.rgb.b);
		++i;
	}
}
