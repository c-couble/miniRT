/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimation_incr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:16:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 13:16:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	estimation_incr(t_engine *engine)
{
	if (engine->scene.caustic.intensity_scalar < 10000)
	{
		engine->scene.caustic.intensity_scalar += 1;
		engine->scene.camera.should_render = 1;
	}
}
