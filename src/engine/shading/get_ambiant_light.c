/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 06:05:01 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 00:08:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "scene.h"


// TODO: use normalized
t_colorf	get_ambiant_light(t_scene *scene)
{
	t_colorf	n_color;

	n_color = color_normalize(scene->ambient_light.color);
	return (color_scale(n_color, scene->ambient_light.ratio));
}
