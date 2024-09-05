/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:00:08 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/26 04:13:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "color.h"
# include "vec3.h"

typedef struct s_triangle
{
	t_vec3			p0;
	t_vec3			p1;
	t_vec3			p2;
	t_color			color;
}	t_triangle;

union	u_object_data;
struct	s_engine;

int	parse_triangle(struct s_engine *engine, union u_object_data *object);

#endif
