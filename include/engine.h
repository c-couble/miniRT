/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:01 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/22 07:27:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "mlx_wrapper.h"
# include "scene.h"

typedef struct s_engine
{
	t_scene	scene;
	t_mlx	mlx;
}	t_engine;

struct	s_ray;

int			init_engine(t_engine *engine, char *scene);
void		clear_engine(t_engine *engine);
void		render_frame(t_engine *engine);
uint32_t	get_light(t_engine *engine, struct s_ray *ray);
uint32_t	get_ambiant_light(t_engine *engine);
uint32_t	get_pixel_color(t_engine *engine, struct s_ray *ray, int depth);
void		run_loop(t_engine *engine);

#endif
