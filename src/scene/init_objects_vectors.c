/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 14:53:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	init_object_vectors(t_scene *scene)
{
	init_vector(&scene->objects, sizeof(t_object));
	init_vector(&scene->lights, sizeof(t_light));
	init_vector(&scene->planes, sizeof(t_object));
}
