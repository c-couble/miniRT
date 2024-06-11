/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/12 01:04:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vec3.h"
# include "color.h"

typedef struct s_plane
{
	t_vec3	coordinates;
	t_vec3	orientation;
	t_color	color;
}	t_plane;

union	u_object_data;

int	parse_plane(union u_object_data *object);

#endif
