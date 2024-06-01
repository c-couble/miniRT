/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 03:58:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/01 04:07:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "engine.h"
# include "color.h"
# include "vector3d.h"

typedef struct s_ray
{
	t_vector3d	startpos;
	t_vector3d	ray;
	t_vector3d	hitpos;
	t_color		color;
}	t_ray;

int	trace_ray(t_engine *engine, t_ray *ray);

#endif
