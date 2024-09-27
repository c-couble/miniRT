/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 04:40:41 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 02:08:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "vec3.h"

void	mat4_view(t_mat4 *mat, t_vec3 *front, t_vec3 *up, t_vec3 *pos)
{
	t_vec3	right;
	t_vec3	forward;

	vec3_cross(front, up, &right);
	forward = *front;
	vec3_scale(&forward, -1);
	mat->matrix[0] = right.x;
	mat->matrix[1] = forward.x;
	mat->matrix[2] = up->x;
	mat->matrix[3] = 0;
	mat->matrix[4] = right.y;
	mat->matrix[5] = forward.y;
	mat->matrix[6] = up->y;
	mat->matrix[7] = 0;
	mat->matrix[8] = right.z;
	mat->matrix[9] = forward.z;
	mat->matrix[10] = up->z;
	mat->matrix[11] = 0;
	mat->matrix[12] = pos->x;
	mat->matrix[13] = pos->y;
	mat->matrix[14] = pos->z;
	mat->matrix[15] = 1;
}
