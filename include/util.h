/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:32:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 00:04:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <sys/types.h>
# include "object/plane.h"
# include "object.h"
# include "ray.h"

int		double_equals(double a, double b);
void	ft_dswap(double *a, double *b);
double	get_axis(t_vec3 *v, int axis);
void	init_material(t_material_data *data);
double	get_biggest_distance(double a, double b);
double	get_closest_distance(double a, double b);
int		get_closest_distance_ptr(double a, double b, double *out);
void	get_hitpos(t_ray *ray, double t);
double	get_theta_axis(t_vec3 *axis, t_vec3 *rot_axis);
double	find_max(double *arr, size_t size);
double	find_mean(double *arr, size_t size);
double	find_min(double *arr, size_t size);
void	print_error(char *err);
double	solve_plane_equation(t_plane *plane, t_ray *ray);
void	ft_dswap(double *a, double *b);
double	rand_range(double min, double max);
void	set_texture_normal(t_object *obj, t_ray *ray, int face);

#endif
