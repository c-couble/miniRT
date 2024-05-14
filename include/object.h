/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 01:16:11 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "object/ambient_light.h"

typedef enum e_object_type
{
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	UNKNOWN_OBJ,
	COMMENT
}	t_object_type;

typedef union u_object_data
{
	t_ambient_light	ambient_light;
}	t_object_data;

typedef struct s_object
{
	t_object_type	type;
	t_object_data	data;
}	t_object;

int	init_object(t_object *object, char *line);
int	parse_camera(union u_object_data *object);
int	parse_cylinder(union u_object_data *object);
int	parse_light(union u_object_data *object);
int	parse_plane(union u_object_data *object);
int	parse_sphere(union u_object_data *object);

#endif
