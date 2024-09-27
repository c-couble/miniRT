/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 06:10:24 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/26 06:12:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

void	mat4_scale(t_mat4 *mat, double scale, double wscale)
{
	mat->matrix[0] = scale;
	mat->matrix[1] = 0;
	mat->matrix[2] = 0;
	mat->matrix[3] = 0;
	mat->matrix[4] = 0;
	mat->matrix[5] = scale;
	mat->matrix[6] = 0;
	mat->matrix[7] = 0;
	mat->matrix[8] = 0;
	mat->matrix[9] = 0;
	mat->matrix[10] = scale;
	mat->matrix[11] = 0;
	mat->matrix[12] = 0;
	mat->matrix[13] = 0;
	mat->matrix[14] = 0;
	mat->matrix[15] = wscale;
}
