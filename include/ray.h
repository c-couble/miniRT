/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 03:58:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/22 09:48:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "engine.h"
# include "color.h"
# include "object/material.h"
# include "vec3.h"

struct	s_object;

typedef struct s_hit_data
{
	t_vec3			hitpos;
	t_vec3			normal;
	t_color			color;
	t_material_data	materials;
}	t_hit_data;

typedef struct s_ray
{
	t_vec3		startpos;
	t_vec3		ray;
	t_vec3		r_ray;
	t_hit_data	data;
}	t_ray;

int	trace_ray(t_engine *engine, t_ray *ray);

#endif
