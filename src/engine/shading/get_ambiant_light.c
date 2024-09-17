/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 06:05:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 18:01:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "engine.h"

uint32_t	get_ambiant_light(t_engine *engine)
{
	return (scale_color(&engine->scene.ambient_light.color
			, engine->scene.ambient_light.ratio));
}
