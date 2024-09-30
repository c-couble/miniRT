/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:40:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 15:02:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "bvh.h"
#include "scene.h"

void	clear_scene(t_scene *scene)
{

	clear_bvh(&scene->bvh);
	clear_caustic(&scene->caustic);
}
