/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:06:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/26 04:13:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "color.h"
# include "vec3.h"

typedef struct s_paraboloid
{
	t_vec3			pos;
	t_vec3			axis;
	double			ray_coef;
	double			height;
	t_color			color;
}	t_paraboloid;

union	u_object_data;
struct	s_engine;

int	parse_paraboloid(struct s_engine *engine, union u_object_data *object);

#endif
