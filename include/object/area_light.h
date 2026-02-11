/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_light.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:35:30 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/06 00:40:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AREA_LIGHT_H
# define AREA_LIGHT_H

# include "color.h"
# include "vec3.h"

typedef struct s_area_light
{
	t_vec3		pos;
	t_vec3		normal;
	t_vec3		axis_u;
	t_vec3		axis_v;
	double		size_u;
	double		size_v;
	double		area;
	double		power;
	t_colorf	color;
}	t_area_light;

struct	s_engine;
union	u_object_data;

int	parse_area_light(struct s_engine *engine, union u_object_data *object);

#endif
