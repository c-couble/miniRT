/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:56:42 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 08:21:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3d.h"

typedef struct s_camera
{
	t_vector3d	coordinates;
	t_vector3d	orientation;
	double		fov;
}	t_camera;

union	u_object_data;
int	parse_camera(union u_object_data *data);

#endif
