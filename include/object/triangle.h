/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:00:08 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/09 23:41:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "vector3d.h"
# include "color.h"

typedef struct s_triangle
{
	t_vector3d	p0;
	t_vector3d	p1;
	t_vector3d	p2;
	t_color		color;
}	t_triangle;

union	u_object_data;

int	parse_triangle(union u_object_data *object);

#endif
