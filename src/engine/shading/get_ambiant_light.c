/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 06:05:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 05:35:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"
#include "engine.h"

uint32_t	get_ambiant_light(t_engine *engine)
{
	return (scale_color(&engine->scene.ambient_light.color
			, engine->scene.ambient_light.ratio));
}
