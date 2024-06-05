/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:06:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/05 01:08:11 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "vector3d.h"
# include "color.h"

typedef struct s_paraboiloid
{
	t_vector3d	coordinates;
	t_vector3d	axis;
	double		diameter;
	double		height;
	t_color		color;
}	t_paraboloid;

union	u_object_data;

int	parse_paraboloid(union u_object_data *object);


# endif
