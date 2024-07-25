/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:43:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/23 05:53:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "obj_3d.h"
# include "vec3.h"

typedef struct s_mesh
{
	char		*name;
	t_vec3		pos;
	t_vec3		orientation;
	double		scale;

	t_obj_3d	*obj_3d;
}	t_mesh;

union	u_object_data;

int	parse_mesh(union u_object_data *object);

#endif