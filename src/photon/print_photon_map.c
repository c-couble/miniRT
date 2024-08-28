/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_photon_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:42:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/28 06:18:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "photon.h"
#include "util.h"

void	print_photon_map(t_vector *photons)
{
	size_t		i;
	t_photon	*curr;

	i = 0;
	while (i < photons->size)
	{
		curr = at_vector(photons, i);
		print_vec3(&curr->pos, "p_ray");
		printf("color r = %d, g = %d, b = %d\n", curr->color.rgb.r,
			curr->color.rgb.b, curr->color.rgb.b);
		++i;
	}
}
