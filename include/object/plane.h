/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/20 02:22:45 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "color.h"
# include "material.h"
# include "vec3.h"

typedef struct s_plane
{
	t_vec3			pos;
	t_vec3			normal;
	t_color			color;
	t_material_data	material;
}	t_plane;

union	u_object_data;

int	parse_plane(union u_object_data *object);

#endif
