/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimation_decr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:16:58 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	estimation_decr(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	if (engine->scene.caustic.intensity_scalar > 0)
	{
		engine->scene.caustic.intensity_scalar -= 1;
		engine->scene.camera.should_render = 1;
	}
}
