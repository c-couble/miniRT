/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:38:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 01:53:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDING_BOX_H
# define BOUNDING_BOX_H

# include "ray.h"

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

struct	s_sphere;
struct	s_paraboloid;
struct	s_cylinder;
struct	s_object;

void		create_empty_aabb(t_aabb *aabb);
void		print_bounding_box(t_bbox *b_box);
void		get_bbox_from_aabb(t_aabb *aabb);
void		get_aabb_from_bbox(t_bbox *bbobx, t_aabb *aabb);
void		print_aabb(t_aabb *aabb, char *str);
double		intersect_aabb(t_ray *ray, t_aabb *aabb);

void		get_sphere_aabb(struct s_sphere *sphere, struct s_object *obj);
void		get_paraboloid_aabb(struct s_paraboloid *pa, struct s_object *obj);
void		get_cylinder_aabb(struct s_cylinder *cyl, struct s_object *obj);

#endif
