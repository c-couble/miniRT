/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:56:52 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/25 17:53:13 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHOTON_H
# define PHOTON_H

#include "vec3.h"
#include "color.h"
#include "vector.h"
#include "sys/types.h"

typedef struct s_photon
{
	t_vec3	pos;
	t_color	color;
}	t_photon;


typedef struct s_engine t_engine;
typedef struct s_ray t_ray;

int		init_photon_map(t_engine *eng);
void	print_photon_map(t_engine *engine);
int		trace_photon(t_engine *engine, t_ray *ph_ray, int depth, t_photon *ph);
void	print_photon_map(t_engine *engine);
double	get_closest_photon(t_engine *engine, t_ray *ray, t_ray *p_ray);
void	sort_photons_axis(t_vector *point, ssize_t start, ssize_t end, int axis);

#endif
