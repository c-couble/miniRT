/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:41:26 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/30 02:18:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include <stdio.h>

t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out)
{
	//t_mat4	result;
	double	determinant;

	determinant =
		mat->matrix[0] * mat->matrix[5] * mat->matrix[10] * mat->matrix[15]
		+ mat->matrix[0] * mat->matrix[6] * mat->matrix[11] * mat->matrix[13]
		+ mat->matrix[0] * mat->matrix[7] * mat->matrix[9] * mat->matrix[14]
		
		- mat->matrix[0] * mat->matrix[7] * mat->matrix[10] * mat->matrix[13]
		- mat->matrix[0] * mat->matrix[6] * mat->matrix[9] * mat->matrix[15]
		- mat->matrix[0] * mat->matrix[5] * mat->matrix[11] * mat->matrix[14]

		- mat->matrix[1] * mat->matrix[4] * mat->matrix[10] * mat->matrix[15]
		- mat->matrix[2] * mat->matrix[4] * mat->matrix[11] * mat->matrix[13]
		- mat->matrix[3] * mat->matrix[4] * mat->matrix[9] * mat->matrix[14]

		+ mat->matrix[3] * mat->matrix[4] * mat->matrix[10] * mat->matrix[13]
		+ mat->matrix[2] * mat->matrix[4] * mat->matrix[9] * mat->matrix[15]
		+ mat->matrix[1] * mat->matrix[4] * mat->matrix[11] * mat->matrix[14]

		+ mat->matrix[1] * mat->matrix[6] * mat->matrix[8] * mat->matrix[15]
		+ mat->matrix[2] * mat->matrix[7] * mat->matrix[8] * mat->matrix[13]
		+ mat->matrix[3] * mat->matrix[5] * mat->matrix[8] * mat->matrix[14]

		- mat->matrix[3] * mat->matrix[6] * mat->matrix[8] * mat->matrix[13]
		- mat->matrix[2] * mat->matrix[5] * mat->matrix[8] * mat->matrix[15]
		- mat->matrix[1] * mat->matrix[7] * mat->matrix[8] * mat->matrix[14]

		- mat->matrix[1] * mat->matrix[6] * mat->matrix[11] * mat->matrix[12]
		- mat->matrix[2] * mat->matrix[7] * mat->matrix[9] * mat->matrix[12]
		- mat->matrix[3] * mat->matrix[5] * mat->matrix[10] * mat->matrix[12]
		
		+ mat->matrix[3] * mat->matrix[6] * mat->matrix[9] * mat->matrix[12]
		+ mat->matrix[2] * mat->matrix[5] * mat->matrix[11] * mat->matrix[12]
		+ mat->matrix[1] * mat->matrix[7] * mat->matrix[10] * mat->matrix[12]
		;
	printf("aaa %lf\n", determinant);
	return (out);
}
