/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 06:05:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:09:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "scene.h"

uint32_t	get_ambiant_light(t_scene *scene)
{
	return (scale_color(&scene->ambient_light.color
			, scene->ambient_light.ratio));
}
