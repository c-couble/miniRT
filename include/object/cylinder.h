/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:15:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/22 03:10:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vector3d.h"
# include "color.h"

typedef struct s_cylinder
{
	t_vector3d	coordinates;
	t_vector3d	axis;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

union	u_object_data;

int	parse_cylinder(union u_object_data *object);

#endif
