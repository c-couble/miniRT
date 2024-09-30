/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_neighbour_decr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:14:29 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 13:15:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	nearest_neighbour_decr(t_engine *engine)
{
	if (engine->scene.caustic.nn_nb > 0)
	{
		engine->scene.caustic.nn_nb -= 1;
		engine->scene.camera.should_render = 1;
	}
}
