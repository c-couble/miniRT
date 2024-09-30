/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 17:06:45 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "color.h"
# include "vec3.h"

typedef struct s_plane
{
	t_vec3			pos;
	t_vec3			normal;
	t_color			color;
}	t_plane;

union	u_object_data;
struct	s_engine;

int	parse_plane(struct s_engine *engine, union u_object_data *object);

#endif
