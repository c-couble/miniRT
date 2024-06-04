/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/03 23:00:28 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "object/ambient_light.h"
# include "object/camera.h"
# include "object/cylinder.h"
# include "object/light.h"
# include "object/plane.h"
# include "object/sphere.h"
# include "ray.h"

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
	t_camera		camera;
	t_cylinder		cylinder;
	t_light			light;
	t_plane			plane;
	t_sphere		sphere;
}	t_object_data;

typedef struct s_object
{
	t_object_type	type;
	t_object_data	data;
}	t_object;

int		init_object(t_object *object, char *line);
double	intersect(t_object *obj, t_ray *ray);
double	intersect_sphere(t_object *obj, t_ray *ray);
double	intersect_cylinder(t_object *obj, t_ray *ray);

#endif
