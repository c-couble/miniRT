/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:40:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 23:18:38 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	clear_scene(t_scene *scene)
{
	clear_vector(&scene->objects);
	clear_vector(&scene->lights);
}
