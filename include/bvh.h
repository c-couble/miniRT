/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 01:52:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "engine.h"
# include "ray.h"
# include "vector.h"
# include "bounding_box.h"

typedef struct s_bvh_node
{
	t_aabb				aabb;
	struct s_bvh_node	*left;
	struct s_bvh_node	*right;
	int					start;
	int					size;
}	t_bvh;

t_bvh		*create_bvh_node(void);
t_bvh		*init_bvh(t_vector *objs);
void		clear_bvh(t_bvh *bvh);
void		update_node_aabb(t_bvh *node, t_vector *objs);
double		get_split_pos_axis(t_bvh *node, int *axis);
double		intersect_bvh(t_ray *ray, t_bvh *node, t_vector *objs);

void		swap_by_axis(t_bvh *bvh, t_vector *objs, double pos, int axis);
void		get_bvh_depth(t_bvh *bvh, int depth, int *depth_ptr);
void		print_node(t_bvh *n, t_vector *objs, char *str);
void		print_objs(t_vector *objs);

int			init_bvh_hooks(t_engine *engine);
void		change_bvh_mode(t_engine *engine);
void		increase_depth_manual(t_engine *engine);
void		increase_depth_persistent(t_engine *engine);
void		decrease_depth_manual(t_engine *engine);
void		decrease_depth_persistent(t_engine *engine);

#endif
