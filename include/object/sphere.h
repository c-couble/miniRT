/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:38:55 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:14:08 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "color.h"
# include "vec3.h"

typedef struct s_sphere
{
	t_vec3			pos;
	double			diameter;
	double			radius;
	t_color			color;
}	t_sphere;

union	u_object_data;
struct	s_engine;

int	parse_sphere(struct s_engine *engine, union u_object_data *object);

#endif
