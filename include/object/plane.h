/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/22 03:09:14 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vector3d.h"
# include "color.h"

typedef struct s_plane
{
	t_vector3d	coordinates;
	t_vector3d	orientation;
	t_color		color;
}	t_plane;

union	u_object_data;

int	parse_plane(union u_object_data *object);

#endif
