/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_photon_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:52:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/03 23:44:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include "vector.h"

void	clear_photon_maps(t_vector *maps)
{
	t_kdtree	**curr;
	size_t		i;

	i = 0;
	while (i < maps->size)
	{
		curr = at_vector(maps, i);
		clear_kdtree(*curr);
		++i;
	}
	clear_vector(maps);
}
