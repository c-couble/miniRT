/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:56:52 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/18 16:15:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHOTON_H
# define PHOTON_H

#include "vec3.h"
#include "color.h"

typedef struct s_photon
{
	t_vec3	pos;
	t_color	color;
}	t_photon;

typedef struct s_engine t_engine;
typedef struct s_ray t_ray;

int	init_photon_map(t_engine *eng);
void	print_photon_map(t_engine *engine);
int	trace_photon(t_engine *engine, t_ray *ph_ray, int depth, t_photon *ph);

#endif
