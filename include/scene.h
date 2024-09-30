/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:38 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 17:19:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object/ambient_light.h"
# include "object/camera.h"
# include "vector.h"

typedef struct s_scene
{
	t_ambient_light	ambient_light;
	int				has_ambient_light;
	t_camera		camera;
	int				has_camera;
	int				has_light;
	t_vector		objects;
	char			*scene_name;
}	t_scene;

int		init_scene(struct s_engine *engine, t_scene *scene, char *file);
void	clear_scene(t_scene *scene);

#endif
