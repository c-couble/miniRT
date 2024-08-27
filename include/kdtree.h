/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:52:23 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 03:56:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KDTREE_H
# define KDTREE_H

#include "photon.h"

typedef struct s_kdtree
{
	t_photon		photon;
	struct s_kdtree	*left;
	struct s_kdtree	*right;
}	t_kdtree;

typedef struct s_kaboul
{
	t_kdtree	*node;
	double		best_dist;
}	t_kaboul;

void		print_kdtree(t_kdtree *node, int depth);
t_kdtree	*init_kdtree(t_vector *photons, int depth);
int			create_kdnode(t_kdtree **node, t_photon *photon);
void		clear_kdtree(t_kdtree *tree);
void	nearest_neighbour(t_kdtree *node, t_kaboul *kaboul, t_vec3 *target, int depth);
t_kdtree *get_nearest_neighbour(t_kaboul *kaboul, t_kdtree *tree, t_vec3 *target);

#endif
