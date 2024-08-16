/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:56:42 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/06 21:16:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "mat4.h"
# include "vec3.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_camera
{
	t_vec3	coordinates;
	t_vec3	front;
	t_vec3	right;
	t_vec3	up;
	t_mat4	projection;
	t_mat4	inverse_projection;
	t_mat4	view;
	t_mat4	inverse_view;
	t_mat4	final;
	size_t	pixel_square_size;
	size_t	frame_width;
	size_t	frame_height;
	double	fov;
	int		locked;
	int		should_render;
}	t_camera;

union	u_object_data;

int		parse_camera(union u_object_data *data);

struct	s_engine;

void	setup_camera(struct s_engine *engine);
void	color_pixels(struct s_engine *engine, size_t i, size_t j, uint32_t c);

int		init_camera_hooks(struct s_engine *engine);
void	camera_mouse_hook(struct s_engine *engine);
void	move_backwards(struct s_engine *engine);
void	move_down(struct s_engine *engine);
void	move_forward(struct s_engine *engine);
void	move_left(struct s_engine *engine);
void	move_right(struct s_engine *engine);
void	move_up(struct s_engine *engine);
void	roll_left(struct s_engine *engine);
void	roll_right(struct s_engine *engine);
void	lock_camera(struct s_engine *engine);

#endif
