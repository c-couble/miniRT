/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:01:15 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:36:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mat4.h"

void	mat4_multiply(t_mat4 *a, t_mat4 *b, t_mat4 *out)
{
	size_t	i;
	size_t	j;
	size_t	k;
	double	value;
	t_mat4	tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			value = 0;
			while (k < 4)
			{
				value += a->matrix[i * 4 + k] * b->matrix[k * 4 + j];
				++k;
			}
			tmp.matrix[i * 4 + j] = value;
			++j;
		}
		++i;
	}
	*out = tmp;
}
