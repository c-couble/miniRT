/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:01 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/11 03:49:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <pthread.h>
# include <stdatomic.h>

# include "color.h"
# include "mlx_wrapper.h"
# include "object/material.h"
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
	int				current_line;
	int				finished_lines;
	int				stop;
	t_material_data	default_material;
	atomic_int		thread_run;
	int				render_width;
	int				render_height;
	size_t			render_size;
	t_color			*render_data;
	t_colorf		*samples;
	size_t			samples_size;
	size_t			sample_nb;
	int				sampling;
}	t_engine;

void		clear_engine(t_engine *engine);
void		clear_threads(t_engine *engine, size_t threads);
int			init_engine(t_engine *engine, char *scene);
int			init_threads(t_engine *engine);
int			init_samples(t_engine *engine);

void		engine_loop_hook(t_engine *engine);
void		engine_focus_in(t_engine *engine);
void		quit_engine(t_engine *engine);
void		*routine(void *arg);

void		render_frame(t_engine *engine);
uint32_t	render_pixel(t_engine *e, t_ray *c_ray, int w, int h);
uint32_t	render_low_quality_pixel(t_engine *engine, t_ray *c_ray);

#endif
