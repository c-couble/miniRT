/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:16:18 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "vector.h"
# include "bounding_box.h"

typedef enum e_bvh_mode
{
	NONE,
	MANUAL,
	PERSISTENT,
}	t_bvh_mode;

typedef struct s_bvh_node
{
	t_aabb				aabb;
	struct s_bvh_node	*left;
	struct s_bvh_node	*right;
	int					start;
	int					size;
}	t_bvh_node;

typedef struct s_bvh
{
	t_bvh_node	*bvh;
	int			depth;
	int			max_depth;
	t_bvh_mode	bvh_mode;
}	t_bvh;

struct	s_ray;
struct	s_engine;

int			init_bvh(t_bvh *bvh, t_vector *objs);
void		clear_bvh(t_bvh *bvh);

t_bvh_node	*create_bvh_node(void);
t_bvh_node	*init_bvh_tree(t_vector *objs);
void		clear_bvh_tree(t_bvh_node *bvh);
void		update_node_aabb(t_bvh_node *node, t_vector *objs);
double		get_split_pos_axis(t_bvh_node *node, int *axis);
double		intersect_bvh(struct s_ray *ray, t_bvh_node *node, t_vector *objs);

void		swap_by_axis(t_bvh_node *bvh, t_vector *objs, double pos, int axis);
void		get_bvh_depth(t_bvh_node *bvh, int depth, int *depth_ptr);
void		print_node(t_bvh_node *n, t_vector *objs, char *str);
void		print_objs(t_vector *objs);

int			init_bvh_hooks(struct s_engine *engine);
void		change_bvh_mode(struct s_engine *engine);
void		increase_depth_manual(struct s_engine *engine);
void		increase_depth_persistent(struct s_engine *engine);
void		decrease_depth_manual(struct s_engine *engine);
void		decrease_depth_persistent(struct s_engine *engine);

#endif
