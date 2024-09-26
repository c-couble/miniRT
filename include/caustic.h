/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caustic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 04:34:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 06:25:41 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAUSTIC_H
# define CAUSTIC_H

# include "bounding_box.h"
# include "kdtree.h"
# include "object/light.h"
# include "vector.h"

typedef	struct s_caustic_map
{
	t_aabb		aabb;
	t_kdtree	*tree;
}	t_caustic_map;

typedef struct s_option t_option;
typedef struct s_engine	t_engine;
typedef struct s_ray	t_ray;

int		init_caustic_maps(t_engine *eng);
void	clear_caustic_maps(t_vector *maps);

void	clear_photon_maps(t_vector *maps);
int		init_photon_map(t_engine *eng);

int		trace_photon(t_engine *engine, t_ray *ph_ray, int depth, t_photon *ph);
void	print_photon_map(t_vector *photons);
double	get_closest_photon(t_engine *engine, t_ray *ray, t_ray *p_ray);
int		generate_photons(t_engine *eng, t_vector *photons, t_light *light);
int		parse_caustic(t_engine *engine, t_option *data, char *arg);

#endif
