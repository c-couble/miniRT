/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 05:51:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "ray.h"
# include "object/triangle.h"
# include "bounding_box.h"
# include "vector.h"

typedef enum e_bvh_mode
{
	NONE,
	SINGLE_LAYER,
	FULL_LAYER,
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

struct	s_engine;

int			init_bvh(t_bvh *bvh, t_vector *objs);
void		clear_bvh(t_bvh *bvh);

t_bvh_node	*create_bvh_node(void);
t_bvh_node	*init_bvh_tree(t_vector *objs);
t_bvh_node	*init_bvh_mesh(struct s_cached_triangle *tri, size_t size);
void		clear_bvh_tree(t_bvh_node *bvh);
void		update_node_aabb(t_bvh_node *node, t_vector *objs);
void		update_node_aabb_mesh(t_bvh_node *n, struct s_cached_triangle *t);
void		swap_by_axis(t_bvh_node *bvh, t_vector *objs, double pos, int axis);
void		swap_tris(t_bvh_node *node, t_cached_triangle *t, double p, int a);
double		get_split_pos_axis(t_bvh_node *node, int *axis);
double		intersect_bvh(t_ray *ray, t_bvh_node *node, t_vector *objs);
double		intersect_bvh_mesh(t_ray *r, t_bvh_node *n, t_cached_triangle *t);

void		get_bvh_depth(t_bvh_node *bvh, int depth, int *depth_ptr);
void		print_node(t_bvh_node *n, t_vector *objs, char *str);
void		print_objs(t_vector *objs);

int			init_bvh_hooks(struct s_engine *engine);
void		change_bvh_mode(struct s_engine *engine);
void		increase_single_layer(struct s_engine *engine);
void		increase_full_layer(struct s_engine *engine);
void		decrease_single_layer(struct s_engine *engine);
void		decrease_full_layer(struct s_engine *engine);

#endif
