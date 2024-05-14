/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:38:55 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 17:40:58 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vector3d.h"
# include "object/rgb.h"

typedef struct s_sphere
{
	t_vector3d	coordinates;
	double		diameter;
	t_rgb		color;
}	t_sphere;

union u_object_data;

int	parse_sphere(union u_object_data *object);

#endif
