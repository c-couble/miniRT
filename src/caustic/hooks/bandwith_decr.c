/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bandwith_decr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:07:19 by lespenel          #+#    #+#             */
/*   Updated: 2024/11/05 03:54:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	bandwith_decr(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	engine->scene.caustic.bandwidth -= 0.001;
	engine->scene.camera.should_render = 1;
}
