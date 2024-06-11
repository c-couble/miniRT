/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 03:58:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:20:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "engine.h"
# include "color.h"
# include "vec3.h"

typedef struct s_ray
{
	t_vec3	startpos;
	t_vec3	ray;
	t_vec3	hitpos;
	t_vec3	normal;
	t_color		color;
}	t_ray;

int	trace_ray(t_engine *engine, t_ray *ray);

#endif
