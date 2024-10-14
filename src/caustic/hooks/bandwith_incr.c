/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bandwith_incr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:04:29 by lespenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:12:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	bandwith_incr(t_engine *engine)
{
	if (engine->scene.camera.locked)
		return ;
	engine->scene.caustic.bandwidth += 0.005;
	engine->scene.camera.should_render = 1;
	update_caustic_aabb(&engine->scene);
}
