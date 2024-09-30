/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:35:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 20:35:47 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

int		parse_vector3d(t_vec3 *vector, double min, double max);
int		parse_normalized_vector3d(t_vec3 *vector);
void	yaw_pitch_to_vector(t_vec3 *vector, double yaw, double pitch);
t_vec3	*vec3_add(t_vec3 *vec1, t_vec3 *vec2, t_vec3 *out);
t_vec3	*vec3_subtract(t_vec3 *vec1, t_vec3 *vec2, t_vec3 *out);
t_vec3	*vec3_scale(t_vec3 *vec, double x);
double	vec3_normalize(t_vec3 *vec);
double	vec3_get_norm(t_vec3 *vec);
double	vec3_dot(t_vec3 *vec1, t_vec3 *vec2);
t_vec3	*vec3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3	*vec3_create(double x, double y, double z, t_vec3 *out);
t_vec3	*vec3_random(t_vec3 *vec, double min, double max);

#endif
