/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:38:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/29 08:19:53 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDING_BOX_H
# define BOUNDING_BOX_H

# include "vec3.h"
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
}	t_aabb;

struct	s_cylinder;
struct	s_mesh;
struct	s_object;
struct	s_paraboloid;
struct	s_ray;
struct	s_engine;
struct	s_scene;
struct	s_sphere;
struct	s_cached_triangle;

void		create_empty_aabb(t_aabb *aabb);
void		get_aabb_center(t_aabb *aabb);
void		get_aabb_from_bbox(t_bbox *bbox, t_aabb *aabb);
int			is_point_iside_aabb(t_vec3 *point, t_aabb *aabb);
void		get_bbox_from_aabb(t_aabb *aabb, t_bbox *bbox);
double		intersect_aabb(struct s_ray *ray, t_aabb *aabb);
void		print_bounding_box(t_bbox *b_box);
void		print_aabb(t_aabb *aabb, char *str);
void		update_caustic_aabb(struct s_scene *scene);

void		get_cached_triangle_aabb(struct s_cached_triangle *t, t_aabb *aabb);
void		get_cylinder_aabb(struct s_cylinder *cyl, t_aabb *aabb);
void		get_caustic_aabb(t_vector *photons, t_aabb *aabb);
void		get_mesh_aabb(struct s_mesh *mesh, t_aabb *aabb);
void		get_objects_aabb(struct s_object *object);
void		get_paraboloid_aabb(struct s_paraboloid *para, t_aabb *aabb);
void		get_sphere_aabb(struct s_sphere *sphere, t_aabb *aabb);

#endif
