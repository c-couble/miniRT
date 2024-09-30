/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:56:42 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 18:12:02 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stddef.h>
# include <stdint.h>
# include "mat4.h"
# include "vec3.h"

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
	double	fov;
}	t_camera;

union	u_object_data;

struct	s_engine;

int		parse_camera(struct s_engine *engine, union u_object_data *data);
void	setup_camera(struct s_engine *engine);
void	create_camera_vectors(t_camera *cam);
void	color_pixels(struct s_engine *engine, size_t i, size_t j, uint32_t c);

int		init_camera_hooks(struct s_engine *engine);

#endif
