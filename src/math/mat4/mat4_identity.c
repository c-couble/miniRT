/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 04:54:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/18 04:55:29 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	*mat4_identity(t_mat4 *out)
{
	out->matrix[0] = 1;
	out->matrix[1] = 0;
	out->matrix[2] = 0;
	out->matrix[3] = 0;
	out->matrix[4] = 0;
	out->matrix[5] = 1;
	out->matrix[6] = 0;
	out->matrix[7] = 0;
	out->matrix[8] = 0;
	out->matrix[9] = 0;
	out->matrix[10] = 1;
	out->matrix[11] = 0;
	out->matrix[12] = 0;
	out->matrix[13] = 0;
	out->matrix[14] = 0;
	out->matrix[15] = 1;
	return (out);
}
