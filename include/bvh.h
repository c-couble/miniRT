/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/14 01:45:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "engine.h"
# include "vec2.h"
# include "vec3.h"
# include "ray.h"
# include "vector.h"

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
	struct	s_bvh_node	*left;
	struct	s_bvh_node	*right;
	t_vector			objects;
}	t_bvh_node;

struct	s_sphere;
struct	s_paraboloid;
struct	s_cylinder;
struct	s_object;

t_bvh_node	*create_bvh_node(void);
t_bvh_node	*init_bvh(t_vector *objs, int depth);
void		clear_bvh(t_bvh_node *bvh);
void		create_empty_aabb(t_aabb *aabb);
void		update_node_aabb(t_bvh_node *node);
double		intersect_bvh(t_ray *ray, t_bvh_node *node);
double		intersect_aabb(t_ray *ray, t_aabb *aabb);

void		print_bounding_box(t_bbox *b_box);
void		get_bounding_box(t_aabb *aabb);
void		get_aabb_from_bbox(t_bbox *bbobx, t_aabb *aabb);

void		print_objs(t_vector *objs);
void		print_aabb(t_aabb *aabb, char *str);

void		draw_line(t_engine *img, t_vec2 *a, t_vec2 *b);
int			draw_bounding_boxes(t_engine *eng);

void		get_sphere_aabb(struct s_sphere *sphere, struct s_object *obj);
void		get_paraboloid_aabb(struct s_paraboloid *sphere, struct s_object *obj);
void		get_cylinder_aabb(struct s_cylinder *para, struct s_object *obj);

#endif
