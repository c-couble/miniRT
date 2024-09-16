/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 22:45:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "engine.h"
# include "ray.h"
# include "vector.h"
#include <stdio.h>

// counterclockwise
typedef struct s_bbox
{
	t_vec3	top[4];
	t_vec3	bottom[4];
}	t_bbox;

typedef struct s_aabb
{
	t_vec3		min;
	t_vec3		max;
	t_vec3		center;
	t_bbox		box;
}	t_aabb;

typedef struct s_bvh_node
{
	t_aabb				aabb;
	struct s_bvh_node	*left;
	struct s_bvh_node	*right;
	int					start;
	int					size;
}	t_bvh_node;

struct	s_sphere;
struct	s_paraboloid;
struct	s_cylinder;
struct	s_object;


t_bvh_node	*create_bvh_node(void);
t_bvh_node	*init_bvh(t_vector *objs);
void		clear_bvh(t_bvh_node *bvh);
void		create_empty_aabb(t_aabb *aabb);
void		update_node_aabb(t_bvh_node *node, t_vector *objs);
double		get_split_pos_axis(t_bvh_node *node, int *axis);
double		intersect_aabb(t_ray *ray, t_aabb *aabb);
double		intersect_bvh(t_ray *ray, t_bvh_node *node, t_vector *objs);
void		print_node(t_bvh_node *n, t_vector *objs, char *str);

void		swap_by_axis(t_bvh_node *bvh, t_vector *objs, double pos, int axis);
void		get_bvh_depth(t_bvh_node *bvh, int depth, int *depth_ptr);
void		print_bounding_box(t_bbox *b_box);
void		get_bounding_box(t_aabb *aabb);
void		get_aabb_from_bbox(t_bbox *bbobx, t_aabb *aabb);

void		print_objs(t_vector *objs);
void		print_aabb(t_aabb *aabb, char *str);

int			init_bvh_hooks(t_engine *engine);
void		change_bvh_mode(t_engine *engine);
void		increase_depth_manual(t_engine *engine);
void		increase_depth_persistent(t_engine *engine);
void		decrease_depth_manual(t_engine *engine);
void		decrease_depth_persistent(t_engine *engine);

void		get_sphere_aabb(struct s_sphere *sphere, struct s_object *obj);
void		get_paraboloid_aabb(struct s_paraboloid *pa, struct s_object *obj);
void		get_cylinder_aabb(struct s_cylinder *cyl, struct s_object *obj);

#endif
