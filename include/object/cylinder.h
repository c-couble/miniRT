/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:15:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:13:37 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "color.h"
# include "vec3.h"

typedef struct s_cylinder
{
	t_vec3			pos;
	t_vec3			axis;
	double			diameter;
	double			radius;
	double			height;
	t_color			color;
}	t_cylinder;

union	u_object_data;
struct	s_engine;

int	parse_cylinder(struct s_engine *engine, union u_object_data *object);

#endif
