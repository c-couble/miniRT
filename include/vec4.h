/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:35:46 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/14 01:56:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

# include "mat4.h"
# include "vec3.h"

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

t_vec4	*vec4_create(t_vec3 *from, double w, t_vec4 *out);
t_vec4	*vec4_mat4_mult(t_vec4 *vec, t_mat4 *mat, t_vec4 *out);
t_vec4	*vec4_divide_nw(t_vec4 *in, double divider, t_vec4 *out);
t_vec4	*vec4_substract_vec3(t_vec4 *a, t_vec3 *b, t_vec4 *out);

#endif
