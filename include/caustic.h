/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caustic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 04:34:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:43:05 by lespenel         ###   ########.fr       */
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

typedef struct s_caustic
{
	t_vector	caustic_maps;
	t_knn		knn;
	int			nn;
	double		bandwidth;
}	t_caustic;

typedef struct s_object t_object ;
typedef struct s_option t_option;
typedef struct s_scene	t_scene;
struct s_engine;
typedef struct s_ray	t_ray;

int		init_caustic(t_scene *scene, t_caustic *caustic);
void	clear_caustic(t_caustic *caustic);
int		init_caustic_maps(t_scene *scene, t_caustic *caustic);
void	clear_caustic_maps(t_vector *maps);

int		trace_photon(t_scene *scene, t_ray *ph_ray, int depth, t_photon *ph);
void	print_photon_map(t_vector *photons);
int		generate_photons(t_scene *eng, t_vector *p, t_object *obj, t_light *light);

int		init_caustic_hooks(struct s_engine *engine);
int		parse_caustic(struct s_engine *engine, t_option *data, char *arg);

#endif
