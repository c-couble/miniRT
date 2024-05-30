/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:35:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/30 04:08:00 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

int		parse_vector3d(t_vector3d *vector, double min, double max);
int		parse_normalized_vector3d(t_vector3d *vector);
void	yaw_pitch_to_vector(t_vector3d *vector, double yaw, double pitch);
void	vector_addition(t_vector3d *vec1, t_vector3d *vec2);
void	vector_multiply(t_vector3d *vec, double x);

#endif
