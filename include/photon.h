/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:56:52 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 21:42:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHOTON_H
# define PHOTON_H

# include "vec3.h"
# include "color.h"

typedef struct s_photon
{
	t_vec3	pos;
	t_color	color;
	double	ratio;
}	t_photon;

#endif
