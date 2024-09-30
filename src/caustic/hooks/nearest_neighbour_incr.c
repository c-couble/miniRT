/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_neighbour_incr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:13:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	nearest_neighbour_incr(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	if (engine->scene.caustic.nn_nb < engine->scene.caustic.knn_max_size - 1)
	{
		engine->scene.caustic.nn_nb += 1;
		engine->scene.camera.should_render = 1;
	}
}
