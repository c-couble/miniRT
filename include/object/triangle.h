/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:00:08 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 01:36:17 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

#include "bounding_box.h"
# include "color.h"
# include "object/material.h"
# include "texture.h"
# include "vec3.h"

typedef struct s_cached_triangle
{
	t_aabb			aabb;
	t_vec3			points[3];
	t_vec3			*point_tx[3];
	t_vec3			e1;
	t_vec3			e2;
	t_vec3			normal;
	t_material_data	*material;
	t_color			color;
}	t_cached_triangle;

typedef struct s_triangle
{
	t_vec3				p0;
	t_vec3				p1;
	t_vec3				p2;
	t_vec3				p0t;
	t_vec3				p1t;
	t_vec3				p2t;
	t_texture			*texture;
	t_color				color;
	t_cached_triangle	cached;
}	t_triangle;

union	u_object_data;
struct	s_engine;

int	parse_triangle(struct s_engine *engine, union u_object_data *object);

#endif
