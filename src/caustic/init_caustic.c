/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:06:50 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:31:49 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "defines.h"
#include "kdtree.h"
#include "vector.h"

int	init_caustic(t_scene *scene, t_caustic *caustic)
{
	caustic->nn = DEFAULT_NN;
	caustic->bandwidth = DEFAULT_BANDWIDTH;
	if (init_knn(&caustic->knn, caustic->nn) == -1)
		return (-1);
	init_vector(&caustic->caustic_maps, sizeof(t_caustic_map));
	if (init_caustic_maps(scene, caustic) == -1)
	{
		clear_knn(&caustic->knn);
		clear_vector(&caustic->caustic_maps);
		return (-1);
	}
	return (0);
}
