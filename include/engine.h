/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:01 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 03:06:32 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <pthread.h>
# include "mlx_wrapper.h"
# include "scene.h"
# include "vector.h"

typedef struct s_engine
{
	t_scene			scene;
	t_mlx			mlx;
	t_vector		objs_3d;
	t_vector		obj_mtls;
	t_vector		textures;
	pthread_t		*threads;
	size_t			thread_count;
	pthread_mutex_t	line_mutex;
	size_t			current_line;
	size_t			finished_lines;
	int				stop;
}	t_engine;

int		init_engine(t_engine *engine, char *scene);
void	clear_engine(t_engine *engine);
void	clear_threads(t_engine *engine, size_t threads);
void	render_frame(t_engine *engine);
void	engine_loop_hook(t_engine *engine);
void	engine_focus_in(t_engine *engine);
void	quit_engine(t_engine *engine);
void	*routine(void *arg);

#endif
