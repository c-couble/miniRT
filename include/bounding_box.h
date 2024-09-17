/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:38:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:00:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDING_BOX_H
# define BOUNDING_BOX_H

# include "vec3.h"

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
}	t_aabb;

struct	s_sphere;
struct	s_paraboloid;
struct	s_cylinder;
struct	s_object;
struct	s_ray;

void		create_empty_aabb(t_aabb *aabb);
void		print_bounding_box(t_bbox *b_box);
void		get_bbox_from_aabb(t_aabb *aabb, t_bbox *bbox);
void		get_aabb_from_bbox(t_bbox *bbox, t_aabb *aabb);
void		print_aabb(t_aabb *aabb, char *str);
double		intersect_aabb(struct s_ray *ray, t_aabb *aabb);

void		get_sphere_aabb(struct s_sphere *sphere, t_aabb *aabb);
void		get_paraboloid_aabb(struct s_paraboloid *para, t_aabb *aabb);
void		get_cylinder_aabb(struct s_cylinder *cyl, t_aabb *aabb);

#endif