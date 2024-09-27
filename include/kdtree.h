/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:52:23 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 06:33:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KDTREE_H
# define KDTREE_H

# include "photon.h"
# include "sys/types.h"
# include "vector.h"

typedef struct s_kdtree
{
	t_photon		photon;
	struct s_kdtree	*left;
	struct s_kdtree	*right;
}	t_kdtree;

typedef struct s_query
{
	t_kdtree	*node;
	double		dist;
}	t_query;

typedef struct s_knn
{
	t_query		*querys;
	size_t		size;
	size_t		count;
	size_t		max_size;
	size_t		farest;
}	t_knn;

int			init_knn(t_knn *knn, size_t k);
void		clear_knn(t_knn *knn);
void		print_knn(t_knn *knn);
void		empty_knn(t_knn *knn);
void		set_knn_size(t_knn *knn, int k);

void		get_knearest_neighbour(t_knn *knn, t_kdtree *tree, t_vec3 *aim);
void		clear_kdtree(t_kdtree *tree);
t_kdtree	*create_kdnode(t_photon *photon);
t_kdtree	*get_nearest_neighbour(t_query *best, t_kdtree *tree, t_vec3 *aim);
t_kdtree	*init_kdtree(t_vector *photons, int depth);
void		print_kdtree(t_kdtree *node, int depth);
void		sort_photons_axis(t_vector *p, ssize_t start, ssize_t end, int axs);

#endif
