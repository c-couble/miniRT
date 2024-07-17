/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:41:26 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/17 02:03:35 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "ft_math.h"
#include <stdio.h>
#include <unistd.h>

t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out)
{
	t_mat4	res;

	res = *mat;
	int r = -1;
	for (int j = 0; j < 4; ++j)
	{
		double max = -1;
		int	k = -1;
		for (int i = r + 1; i < 4; ++i)
		{
			if (ft_abs(res.matrix[i * 4 + j]) > max)
			{
				max = res.matrix[i * 4 + j];
				k = i;
			}
		}

		if (mat->matrix[k * 4 + j] != 0)
		{
			++r;
			for (int l = 0; l < 4; ++l)
			{
				res.matrix[k * 4 + l] /= mat->matrix[k * 4 + j];
				if (k != r)
				{
					int tmp;
					tmp = k;
					k = r;
					r = tmp;
				}
			}
		}
	}
	return (out);
}
