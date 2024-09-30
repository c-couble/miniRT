/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:06:50 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:33:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"
#include "caustic.h"
#include "defines.h"
#include "kdtree.h"
#include "vector.h"

static int	init_knns(t_caustic *caustic);

int	init_caustic(t_scene *scene, t_caustic *caustic)
{
	caustic->nn_nb = DEFAULT_NN;
	caustic->bandwidth = DEFAULT_BANDWIDTH;
	caustic->knn_max_size = KNN_MAX;
	caustic->knn_nb = THREADS;
	if (init_knns(caustic) == -1)
		return (-1);
	init_vector(&caustic->caustic_maps, sizeof(t_caustic_map));
	if (init_caustic_maps(scene, caustic) == -1)
	{
		clear_knns(caustic->knn, caustic->knn_nb);
		clear_vector(&caustic->caustic_maps);
		return (-1);
	}
	return (0);
}

static int	init_knns(t_caustic *caustic)
{
	size_t	i;

	caustic->knn = malloc(sizeof(t_knn) * caustic->knn_nb);
	if (caustic->knn == NULL)
		return (-1);
	i = 0;
	while (i < caustic->knn_nb)
	{
		if (init_knn(&caustic->knn[i], caustic->nn_nb) == -1)
		{
			clear_knns(caustic->knn, caustic->knn_nb);
			return (-1);
		}
		++i;
	}
	return (0);
}
