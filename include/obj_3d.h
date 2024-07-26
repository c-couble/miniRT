/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:01:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:31:38 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_3D
# define OBJ_3D

# include "vector.h"
# include <stddef.h>

typedef struct s_obj_3d
{
	const char	*file_name;
	t_vector	vertices;
	t_vector	texture_coordinates;
	t_vector	vertex_normals;
	t_vector	space_vertices;
	t_vector	faces;
}	t_obj_3d;

typedef struct s_face_point
{
	size_t	vertice_id;
	size_t	texture_id;
	size_t	normal_id;
}	t_polygon_point;

typedef struct s_polygon
{
	t_polygon_point	points[3];
}	t_polygon;

typedef enum e_obj_line_type
{
	VERTICE,
	VERTEX_NORMAL,
	TEXTURE_COORD,
	SPACE_VERTICE,
	POLYGON
}	t_obj_line_type;

struct	s_engine;

t_obj_3d	*parse_obj_if_needed(struct s_engine *engine, const char *file);
int			parse_obj_file(t_obj_3d *obj, const char *file);

#endif
