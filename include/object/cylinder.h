/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:15:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/20 02:21:52 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "color.h"
# include "material.h"
# include "vec3.h"

typedef struct s_cylinder
{
	t_vec3			pos;
	t_vec3			axis;
	double			diameter;
	double			radius;
	double			height;
	t_color			color;
	t_material_data	material;
}	t_cylinder;

union	u_object_data;

int	parse_cylinder(union u_object_data *object);

#endif
