/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 13:15:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "engine.h"
# include "vec2.h"
# include "vec3.h"
# include "ray.h"
# include "vector.h"

typedef struct s_3d_aabb
{
	t_vec3	cube[8];
}	t_3d_aabb;

typedef struct s_aabb
{
	t_vec3		min;
	t_vec3		max;
	t_vec3		center;
	t_3d_aabb	box;
}	t_aabb;

typedef struct s_bvh_node
{
	t_aabb				aabb;
	struct	s_bvh_node	*left;
	struct	s_bvh_node	*right;
	t_vector			objects;
}	t_bvh_node;

struct	s_sphere;
struct	s_object;

t_bvh_node	*create_bvh_node(void);
t_bvh_node	*init_bvh(t_vector *objs, int depth);
void		clear_bvh(t_bvh_node *bvh);
void		create_empty_aabb(t_aabb *aabb);
void		update_node_aabb(t_bvh_node *node);
double		intersect_bvh(t_ray *ray, t_bvh_node *node);

void	print_objs(t_vector *objs);
double		intersect_aabb(t_ray *ray, t_aabb *aabb);
void		draw_line(t_engine *img, t_vec2 *a, t_vec2 *b);
void		print_aabb(t_aabb *aabb, char *str);
void		print_3d_aabb(t_3d_aabb *aabbb);
int			draw_bounding_box(t_engine *eng);
void		get_sphere_aabb(struct s_sphere *sphere, struct s_object *obj);
void		get_3d_aabb(t_aabb *aabb);

#endif
