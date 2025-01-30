/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:56:42 by ccouble           #+#    #+#             */
/*   Updated: 2025/01/30 17:36:44 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stddef.h>
# include <stdint.h>
# include "mat4.h"
# include "vec3.h"

typedef enum e_rtype
{
	CLASSIC,
	NORMAL,
	UV_MAP,
	BOUNDING_BOX
}	t_rtype;

typedef struct s_camera
{
	t_vec3	coordinates;
	t_vec3	front;
	t_vec3	right;
	t_vec3	up;
	t_mat4	perspective;
	t_mat4	inv_projection;
	t_mat4	proj_file;
	t_mat4	inv_proj_file;
	t_mat4	view;
	t_mat4	inverse_view;
	t_mat4	final;
	size_t	pixel_square_size;
	int		frame_width;
	int		frame_height;
	double	fov;
	double	sensitivity;
	double	speed;
	size_t	last_frame_time;
	int		locked;
	int		should_render;
	int		save;
	t_rtype	render_type;
}	t_camera;

union	u_object_data;

struct	s_engine;

int		parse_camera(struct s_engine *engine, union u_object_data *data);
void	setup_camera(struct s_engine *engine);
void	create_camera_vectors(t_camera *cam);
void	color_pixels(struct s_engine *engine, int i, int j, uint32_t c);

int		init_camera_hooks(struct s_engine *engine);
void	camera_mouse_hook(struct s_engine *engine);
void	move_camera(t_camera *camera, t_vec3 *axis, int invert);
void	move_backwards(struct s_engine *engine);
void	move_down(struct s_engine *engine);
void	move_forward(struct s_engine *engine);
void	move_left(struct s_engine *engine);
void	move_right(struct s_engine *engine);
void	move_up(struct s_engine *engine);
void	print_camera_pos(struct s_engine *engine);
void	reset_roll_angle(struct s_engine *engine);
void	roll_left(struct s_engine *engine);
void	roll_right(struct s_engine *engine);
void	lock_camera(struct s_engine *engine);
void	save_render(struct s_engine *engine);
void	speed_down(struct s_engine *engine);
void	speed_up(struct s_engine *engine);
void	change_render_mode(struct s_engine *engine);

#endif
