/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:01 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/21 05:12:50 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "mlx_wrapper.h"
# include "scene.h"
#include "vector.h"

typedef struct s_engine
{
	t_scene		scene;
	t_mlx		mlx;
	t_vector	objs_3d;
}	t_engine;

int		init_engine(t_engine *engine, char *scene);
void	clear_engine(t_engine *engine);
void	render_frame(t_engine *engine);
struct	s_ray;
t_color	get_light(t_engine *engine, struct s_ray *ray);
void	run_loop(t_engine *engine);

#endif
