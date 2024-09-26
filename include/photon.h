/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:56:52 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 03:55:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHOTON_H
# define PHOTON_H

# include "vec3.h"
# include "color.h"
# include "object/light.h"
# include "vector.h"

typedef struct s_photon
{
	t_vec3	pos;
	t_vec3	origin;
	t_color	color;
	double	ratio;
}	t_photon;

typedef struct s_option t_option;
typedef struct s_engine	t_engine;
typedef struct s_ray	t_ray;

void	clear_photon_maps(t_vector *maps);
int		init_photon_map(t_engine *eng);
int		trace_photon(t_engine *engine, t_ray *ph_ray, int depth, t_photon *ph);
void	print_photon_map(t_vector *photons);
double	get_closest_photon(t_engine *engine, t_ray *ray, t_ray *p_ray);
int		generate_photons(t_engine *eng, t_vector *photons, t_light *light);
int		parse_caustic(t_engine *engine, t_option *data, char *arg);

#endif
