/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:43:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 08:59:39 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "bvh.h"
# include "obj_3d.h"
# include "vec3.h"

typedef struct s_mesh
{
	t_bvh_node			*bvh;
	t_vec3				pos;
	t_vec3				front;
	t_vec3				up;
	double				scale;
	t_obj_3d			*obj_3d;
	t_cached_triangle	*cache;
	size_t				triangles;
	int					gouraud_shading;
}	t_mesh;

union	u_object_data;
struct	s_engine;

int		parse_mesh(struct s_engine *engine, union u_object_data *object);
int		build_obj_cache(t_mesh *mesh);

#endif
