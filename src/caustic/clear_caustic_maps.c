/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_caustic_maps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 05:07:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 23:03:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "kdtree.h"
#include "vector.h"

void	clear_caustic_maps(t_vector *maps)
{
	t_caustic_map	*map;
	size_t			i;

	i = 0;
	map = maps->array;
	while (i < maps->size)
	{
		clear_kdtree(map[i].tree);
		++i;
	}
	clear_vector(maps);
}
