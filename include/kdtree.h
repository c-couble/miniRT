/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:52:23 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/30 02:05:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KDTREE_H
# define KDTREE_H

# include "photon.h"

typedef struct s_kdtree
{
	t_photon		photon;
	struct s_kdtree	*left;
	struct s_kdtree	*right;
}	t_kdtree;

typedef struct s_query
{
	t_kdtree	*node;
	double		best_dist;
}	t_query;

void		clear_kdtree(t_kdtree *tree);
t_kdtree	*create_kdnode(t_photon *photon);
double		get_axis(t_vec3 *v, int axis);
t_kdtree	*get_nearest_neighbour(t_query *best, t_kdtree *tree, t_vec3 *aim);
t_kdtree	*init_kdtree(t_vector *photons, int depth);
void		print_kdtree(t_kdtree *node, int depth);

#endif
