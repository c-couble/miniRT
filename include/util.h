/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:32:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/18 14:27:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "object/plane.h"
# include "ray.h"

void	print_error(char *err);
double	get_bigest_distance(double a, double b);
double	get_closest_distance(double a, double b);
int		get_closest_distance_ptr(double a, double b, double *out);
double	solve_plane_equation(t_plane *plane, t_ray *ray);
void	get_hitpos(t_ray *ray, double t);
void	ft_dswap(double *a, double *b);
void	print_vec3(t_vec3 *ray, char *str);

#endif
