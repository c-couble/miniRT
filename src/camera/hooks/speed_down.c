/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:43:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 02:58:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	speed_down(t_engine *engine)
{
	if (engine->scene.camera.speed > 0)
		engine->scene.camera.speed -= 1;
}
