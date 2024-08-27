/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 06:05:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/12 07:44:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "color_util.h"

uint32_t	get_ambiant_light(t_engine *engine)
{
	return (scale_color(&engine->scene.ambient_light.color
			, engine->scene.ambient_light.ratio));
}
