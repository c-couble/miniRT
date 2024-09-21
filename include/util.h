/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:32:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/21 22:11:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <sys/types.h>
# include "object/plane.h"
# include "ray.h"

double	get_axis(t_vec3 *v, int axis);
int		double_equals(double a, double b);
void	print_error(char *err);
double	get_biggest_distance(double a, double b);
double	get_closest_distance(double a, double b);
int		get_closest_distance_ptr(double a, double b, double *out);
double	solve_plane_equation(t_plane *plane, t_ray *ray);
void	get_hitpos(t_ray *ray, double t);
double	get_theta_axis(t_vec3 *axis, t_vec3 *rot_axis);
double	find_max(double *arr, size_t size);
double	find_mean(double *arr, size_t size);
double	find_min(double *arr, size_t size);
void	ft_dswap(double *a, double *b);
double	rand_range(double min, double max);

#endif
