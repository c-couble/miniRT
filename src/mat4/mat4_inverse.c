/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:41:26 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/17 02:00:37 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include <stdio.h>
#include <unistd.h>

static inline double	get_determinant(t_mat4 *mat);

t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out)
{
	t_mat4	adjudant;
	const	double	determinant = get_determinant(mat);

	if (determinant == 0)
		return (NULL);
	adjudant.matrix[0] = 
		+ mat->matrix[5] * mat->matrix[10] * mat->matrix[15]
		+ mat->matrix[6] * mat->matrix[11] * mat->matrix[13]
		+ mat->matrix[7] * mat->matrix[9] * mat->matrix[14]
		- mat->matrix[7] * mat->matrix[10] * mat->matrix[13]
		- mat->matrix[6] * mat->matrix[9] * mat->matrix[15]
		- mat->matrix[5] * mat->matrix[11] * mat->matrix[14];
	adjudant.matrix[1] = 
		- mat->matrix[1] * mat->matrix[10] * mat->matrix[15]
		- mat->matrix[2] * mat->matrix[11] * mat->matrix[13]
		- mat->matrix[3] * mat->matrix[9] * mat->matrix[14]
		+ mat->matrix[3] * mat->matrix[10] * mat->matrix[13]
		+ mat->matrix[2] * mat->matrix[9] * mat->matrix[15]
		+ mat->matrix[1] * mat->matrix[11] * mat->matrix[14];
	adjudant.matrix[2] = 
		+ mat->matrix[1] * mat->matrix[6] * mat->matrix[15]
		+ mat->matrix[2] * mat->matrix[7] * mat->matrix[13]
		+ mat->matrix[3] * mat->matrix[5] * mat->matrix[14]
		- mat->matrix[3] * mat->matrix[6] * mat->matrix[13]
		- mat->matrix[2] * mat->matrix[5] * mat->matrix[15]
		- mat->matrix[1] * mat->matrix[7] * mat->matrix[14];
	adjudant.matrix[3] = 
		- mat->matrix[1] * mat->matrix[6] * mat->matrix[11]
		- mat->matrix[2] * mat->matrix[7] * mat->matrix[9]
		- mat->matrix[3] * mat->matrix[5] * mat->matrix[10]
		+ mat->matrix[3] * mat->matrix[6] * mat->matrix[9]
		+ mat->matrix[2] * mat->matrix[5] * mat->matrix[11]
		+ mat->matrix[1] * mat->matrix[7] * mat->matrix[10];

	adjudant.matrix[4] = 
		- mat->matrix[4] * mat->matrix[10] * mat->matrix[15]
		- mat->matrix[6] * mat->matrix[11] * mat->matrix[12]
		- mat->matrix[7] * mat->matrix[8] * mat->matrix[14]
		+ mat->matrix[7] * mat->matrix[10] * mat->matrix[12]
		+ mat->matrix[6] * mat->matrix[8] * mat->matrix[15]
		+ mat->matrix[4] * mat->matrix[11] * mat->matrix[14];
	adjudant.matrix[5] =
		+ mat->matrix[0] * mat->matrix[10] * mat->matrix[15]
		+ mat->matrix[2] * mat->matrix[11] * mat->matrix[12]
		+ mat->matrix[3] * mat->matrix[8] * mat->matrix[14]
		- mat->matrix[3] * mat->matrix[10] * mat->matrix[12]
		- mat->matrix[2] * mat->matrix[8] * mat->matrix[15]
		- mat->matrix[0] * mat->matrix[11] * mat->matrix[14];
	adjudant.matrix[6] =
		- mat->matrix[0] * mat->matrix[6] * mat->matrix[15]
		- mat->matrix[2] * mat->matrix[7] * mat->matrix[12]
		- mat->matrix[3] * mat->matrix[4] * mat->matrix[14]
		+ mat->matrix[3] * mat->matrix[6] * mat->matrix[12]
		+ mat->matrix[2] * mat->matrix[4] * mat->matrix[15]
		+ mat->matrix[0] * mat->matrix[7] * mat->matrix[14];
	adjudant.matrix[7] =
		+ mat->matrix[0] * mat->matrix[6] * mat->matrix[11]
		+ mat->matrix[2] * mat->matrix[7] * mat->matrix[8]
		+ mat->matrix[3] * mat->matrix[4] * mat->matrix[10]
		- mat->matrix[3] * mat->matrix[6] * mat->matrix[8]
		- mat->matrix[2] * mat->matrix[4] * mat->matrix[11]
		- mat->matrix[0] * mat->matrix[7] * mat->matrix[10];

	adjudant.matrix[8] =
		+ mat->matrix[4] * mat->matrix[9] * mat->matrix[15]
		+ mat->matrix[5] * mat->matrix[11] * mat->matrix[12]
		+ mat->matrix[7] * mat->matrix[8] * mat->matrix[13]
		- mat->matrix[7] * mat->matrix[9] * mat->matrix[12]
		- mat->matrix[5] * mat->matrix[8] * mat->matrix[15]
		- mat->matrix[4] * mat->matrix[11] * mat->matrix[13];
	adjudant.matrix[9] =
		- mat->matrix[0] * mat->matrix[9] * mat->matrix[15]
		- mat->matrix[1] * mat->matrix[11] * mat->matrix[12]
		- mat->matrix[3] * mat->matrix[8] * mat->matrix[13]
		+ mat->matrix[3] * mat->matrix[9] * mat->matrix[12]
		+ mat->matrix[1] * mat->matrix[8] * mat->matrix[15]
		+ mat->matrix[0] * mat->matrix[11] * mat->matrix[13];
	adjudant.matrix[10] =
		+ mat->matrix[0] * mat->matrix[5] * mat->matrix[15]
		+ mat->matrix[1] * mat->matrix[7] * mat->matrix[12]
		+ mat->matrix[3] * mat->matrix[4] * mat->matrix[13]
		- mat->matrix[3] * mat->matrix[5] * mat->matrix[12]
		- mat->matrix[1] * mat->matrix[4] * mat->matrix[15]
		- mat->matrix[0] * mat->matrix[7] * mat->matrix[13];
	adjudant.matrix[11] =
		- mat->matrix[0] * mat->matrix[5] * mat->matrix[11]
		- mat->matrix[1] * mat->matrix[7] * mat->matrix[8]
		- mat->matrix[3] * mat->matrix[4] * mat->matrix[9]
		+ mat->matrix[3] * mat->matrix[5] * mat->matrix[8]
		+ mat->matrix[1] * mat->matrix[4] * mat->matrix[11]
		+ mat->matrix[0] * mat->matrix[7] * mat->matrix[9];

	adjudant.matrix[12] =
		- mat->matrix[4] * mat->matrix[9] * mat->matrix[14]
		- mat->matrix[5] * mat->matrix[10] * mat->matrix[12]
		- mat->matrix[6] * mat->matrix[8] * mat->matrix[13]
		+ mat->matrix[6] * mat->matrix[9] * mat->matrix[12]
		+ mat->matrix[5] * mat->matrix[8] * mat->matrix[14]
		+ mat->matrix[4] * mat->matrix[10] * mat->matrix[13];
	adjudant.matrix[13] =
		+ mat->matrix[0] * mat->matrix[9] * mat->matrix[14]
		+ mat->matrix[1] * mat->matrix[10] * mat->matrix[12]
		+ mat->matrix[2] * mat->matrix[8] * mat->matrix[13]
		- mat->matrix[2] * mat->matrix[9] * mat->matrix[12]
		- mat->matrix[1] * mat->matrix[8] * mat->matrix[14]
		- mat->matrix[0] * mat->matrix[10] * mat->matrix[13];
	adjudant.matrix[14] =
		- mat->matrix[0] * mat->matrix[5] * mat->matrix[14]
		- mat->matrix[1] * mat->matrix[6] * mat->matrix[12]
		- mat->matrix[2] * mat->matrix[4] * mat->matrix[13]
		+ mat->matrix[2] * mat->matrix[5] * mat->matrix[12]
		+ mat->matrix[1] * mat->matrix[4] * mat->matrix[14]
		+ mat->matrix[0] * mat->matrix[6] * mat->matrix[13];
	adjudant.matrix[15] =
		+ mat->matrix[0] * mat->matrix[5] * mat->matrix[10]
		+ mat->matrix[1] * mat->matrix[6] * mat->matrix[8]
		+ mat->matrix[2] * mat->matrix[4] * mat->matrix[9]
		- mat->matrix[2] * mat->matrix[5] * mat->matrix[8]
		- mat->matrix[1] * mat->matrix[4] * mat->matrix[10]
		- mat->matrix[0] * mat->matrix[6] * mat->matrix[9];
	printf("adj:\n");
	mat4_print(&adjudant);
		 
	printf("deter %lf\n", determinant);
	size_t	i;
	i = 0;
	double	coeff = 1 / determinant;
	while (i < 16)
	{
		out->matrix[i] = coeff * adjudant.matrix[i];
		++i;
	}
	mat4_print(out);
	return (out);
}

static inline double	get_determinant(t_mat4 *mat)
{
	return(
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
		+ mat->matrix[1] * mat->matrix[7] * mat->matrix[10] * mat->matrix[12]);
}
