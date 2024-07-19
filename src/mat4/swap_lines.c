/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:22:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/19 03:24:05 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

void	swap_lines(t_mat4 *mat, int r, int k)
{
	int		i;
	double	tmp;

	if (k != r)
	{
		i = 0;
		while (i < 4)
		{
			tmp = mat->matrix[k * 4 + i];
			mat->matrix[k * 4 + i] = mat->matrix[r * 4 + i];
			mat->matrix[r * 4 + i] = tmp;
			++i;
		}
	}
}
