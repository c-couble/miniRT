/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:31:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 17:15:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "engine.h"
# include "vec3.h"
# include "vec2.h"

typedef struct s_3d_aabb
{
	t_vec3	cube[8];
}	t_3d_aabb;

typedef struct s_aabb
{
	t_vec3	min;
	t_vec3	max;
	t_3d_aabb	box;
}	t_aabb;

struct	s_sphere;

void	draw_line(t_engine *img, t_vec2 *a, t_vec2 *b);
void	print_aabb(t_aabb *aabb, char *str);
void	print_3d_aabb(t_3d_aabb *aabbb);
int		draw_bounding_box(t_engine *eng);
void	get_sphere_aabb(t_aabb *aabb, struct s_sphere *sphere);
void	get_3d_aabb(t_aabb *aabb);

#endif
