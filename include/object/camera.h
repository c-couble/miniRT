/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:56:42 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/17 01:31:07 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "mat4.h"
# include "vec3.h"

typedef struct s_camera
{
	t_vec3	coordinates;
	t_vec3	orientation;
	t_mat4	projection;
	t_mat4	inverse_projection;
	t_mat4	view;
	t_mat4	inverse_view;
	t_mat4	final;
	double	fov;
	double	pitch;
	double	yaw;
	double	width;
	double	height;
}	t_camera;

union	u_object_data;

int		parse_camera(union u_object_data *data);

struct	s_engine;

void	setup_camera(struct s_engine *engine);

#endif
