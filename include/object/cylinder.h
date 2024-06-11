/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:15:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:19:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vec3.h"
# include "color.h"

typedef struct s_cylinder
{
	t_vec3	coordinates;
	t_vec3	axis;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

union	u_object_data;

int	parse_cylinder(union u_object_data *object);

#endif
