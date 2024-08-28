/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 06:22:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/29 07:12:54 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "vec3.h"

typedef struct s_quaternion
{
	double	a;
	t_vec3	vec;
}	t_quaternion;

void	quaternion_mult(t_quaternion *a, t_quaternion *b, t_quaternion *out);
void	quaternion_inv(t_quaternion *q, t_quaternion *out);
void	quaternion_rotate(t_vec3 *p, t_vec3 *axis, double angle, t_vec3 *out);

#endif
