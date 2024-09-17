/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 03:58:48 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/17 21:16:19 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "color.h"
# include "object/material.h"
# include "vec3.h"

struct	s_object;
struct	s_texture;

typedef struct s_hit_data
{
	t_vec3				hitpos;
	t_vec3				normal;
	t_vec3				raw_normal;
	t_color				color;
	double				u;
	double				v;
	struct s_object		*obj;
	struct s_texture	*texture;
	t_material_data		materials;
}	t_hit_data;

typedef struct s_ray
{
	t_vec3		startpos;
	t_vec3		ray;
	t_hit_data	data;
	double		inv_x;
	double		inv_y;
	double		inv_z;
}	t_ray;

struct	s_engine;

int		trace_ray(struct s_engine *engine, t_ray *ray);
void	get_inv_dir(t_ray *ray);

#endif
