/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:56:52 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/18 14:05:51 by lespenel         ###   ########.fr       */
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

int	init_photon_map(t_engine *eng);

#endif
