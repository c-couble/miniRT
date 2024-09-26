/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:01:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/26 06:30:38 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_3D_H
# define OBJ_3D_H

# include <stddef.h>
# include "obj_mtl.h"
# include "object/material.h"
# include "object/triangle.h"
# include "vector.h"

typedef struct s_obj_3d
{
	t_vector		vertices;
	t_vector		tx_coords;
	t_vector		vertex_normals;
	t_vector		space_vertices;
	t_vector		faces;
	char			*file_name;
	t_obj_mtl		*mtl;
	t_material_data	*current_material;
}	t_obj_3d;

typedef struct s_face_point
{
	size_t	vertice_id;
	size_t	tx_id;
	size_t	normal_id;
}	t_polygon_point;

typedef struct s_polygon
{
	t_polygon_point		points[3];
	t_material_data		*material;
}	t_polygon;

typedef enum e_obj_line_type
{
	MTLLIB,
	USEMTL,
	VERTICE,
	VERTEX_NORMAL,
	TEXTURE_COORD,
	SPACE_VERTICE,
	POLYGON
}	t_obj_line_type;

struct	s_engine;

t_obj_3d	*parse_obj_if_needed(struct s_engine *engine, char *file);
int			parse_obj_file(struct s_engine *engine, t_obj_3d *obj, char *file);
void		clear_obj_3d(t_obj_3d *obj);
void		clear_objs_3d(t_vector *objs_3d);
int			parse_f(struct s_engine *engine, t_obj_3d *obj, char *line);
int			parse_vp(struct s_engine *engine, t_obj_3d *obj, char *line);
int			parse_usemtl(struct s_engine *engine, t_obj_3d *obj, char *line);
int			parse_vn(struct s_engine *engine, t_obj_3d *obj, char *line);
int			parse_v(struct s_engine *engine, t_obj_3d *obj, char *line);
int			parse_mtllib(struct s_engine *engine, t_obj_3d *obj, char *line);
int			parse_vt(struct s_engine *engine, t_obj_3d *obj, char *line);

#endif
