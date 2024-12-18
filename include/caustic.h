/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caustic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 04:34:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 15:28:53 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAUSTIC_H
# define CAUSTIC_H

# include "bounding_box.h"
# include "object.h"
# include "kdtree.h"
# include "object/light.h"
# include "vector.h"

typedef struct s_caustic_map
{
	t_aabb		aabb;
	t_kdtree	*tree;
}	t_caustic_map;

typedef struct s_caustic
{
	t_vector	caustic_maps;
	t_knn		*knn;
	size_t		knn_nb;
	size_t		knn_max_size;
	size_t		nn_nb;
	size_t		intensity_scalar;
	double		bandwidth;
}	t_caustic;

struct	s_engine;
struct	s_scene;

int		init_caustic(struct s_scene *scene, t_caustic *caustic);
void	clear_caustic(t_caustic *caustic);
int		init_caustic_maps(struct s_scene *scene);
void	clear_caustic_maps(t_vector *maps);

int		parse_caustic(struct s_engine *engine, t_option *data, char *arg);
double	density_estimation(t_knn *knn, double bandwidth);
int		trace_photon(struct s_scene *s, t_ray *ph_ray, int depth, t_photon *ph);
void	print_photon_map(t_vector *photons);
int		get_photons(struct s_scene *s, t_vector *p, t_object *obj, t_light *l);

int		init_caustic_hooks(struct s_engine *engine);
void	bandwith_incr(struct s_engine *engine);
void	bandwith_decr(struct s_engine *engine);
void	nearest_neighbour_incr(struct s_engine *engine);
void	nearest_neighbour_decr(struct s_engine *engine);
void	estimation_incr(struct s_engine *engine);
void	estimation_decr(struct s_engine *engine);

#endif
