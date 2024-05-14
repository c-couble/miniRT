/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:38 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/13 22:42:35 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

typedef struct s_scene
{
	t_vector	objects;
	char		*scene_name;
}	t_scene;

int	init_scene(t_scene *scene, char *file);

#endif
