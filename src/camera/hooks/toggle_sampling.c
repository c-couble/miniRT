/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_sampling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 03:40:50 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/11 03:41:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "engine.h"

void	toggle_sampling(t_engine *engine)
{
	if (engine->sampling)
	{
		printf("sampling off\n");
		if (engine->scene.camera.locked)
		{
			engine->scene.camera.should_render = 0;
			return ;
		}
		engine->sampling = 0;
		engine->sample_nb = 1;
	}
	else
	{
		printf("sampling on\n");
		if (engine->scene.camera.locked)
			engine->scene.camera.should_render = 1;
		engine->sampling = 1;
		engine->sample_nb = 1;
	}
}
