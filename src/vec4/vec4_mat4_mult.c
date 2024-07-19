/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mat4_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 04:01:53 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/17 00:33:57 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

t_vec4	*vec4_mat4_mult(t_vec4 *vec, t_mat4 *mat, t_vec4 *out)
{
	t_vec4	tmp;

	tmp.x = vec->x * mat->matrix[0]
		+ vec->y * mat->matrix[4]
		+ vec->z * mat->matrix[8]
		+ vec->w * mat->matrix[12];
	tmp.y = vec->x * mat->matrix[1]
		+ vec->y * mat->matrix[5]
		+ vec->z * mat->matrix[9]
		+ vec->w * mat->matrix[13];
	tmp.z = vec->x * mat->matrix[2]
		+ vec->y * mat->matrix[6]
		+ vec->z * mat->matrix[10]
		+ vec->w * mat->matrix[14];
	tmp.w = vec->x * mat->matrix[3]
		+ vec->y * mat->matrix[7]
		+ vec->z * mat->matrix[11]
		+ vec->w * mat->matrix[15];
	*out = tmp;
	return (out);
}
