/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 05:02:15 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/18 05:47:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static double	*access_gauss(t_mat4 *left, t_mat4 *right, int i, int j);
static void		gauss_reduction(t_mat4 *left, t_mat4 *right);

t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out)
{
	t_mat4	left;
	t_mat4	right;

	left = *mat;
	mat4_identity(&right);
	mat4_print(&left);
	mat4_print(&right);
	gauss_reduction(&left, &right);
	printf("INVERTED \n\n");
	mat4_print(&left);
	mat4_print(&right);
	(void) access_gauss;
	return (out);
}

static void		gauss_reduction(t_mat4 *left, t_mat4 *right)
{
	int r = -1;
	int	cols = 8;
	int rows = 4;
	for (int j = 0; j < cols; ++j)
	{
		mat4_print(left);
		printf("SEP\n");
		mat4_print(right);
		double max = -1;
		int	k = 0;
		for (int i = r + 1; i < rows; ++i)
		{
			if (ft_abs(*access_gauss(left, right, i, j)) > max)
			{
				max = *access_gauss(left, right, i, j);
				k = i;
				printf("%d\n", i);
			}
		}

		printf("k=%d r=%d j=%d\n", k, r, j);
		if (*access_gauss(left, right, k, j) != 0)
		{
			++r;
			double a = *access_gauss(left, right, k, j);
			for (int l = 0; l < cols; ++l)
			{
				*access_gauss(left, right, k, l) /= a;
			}
			if (k != r)
			{
				for (int l = 0; l < cols; ++l)
				{
					double tmp;
					tmp = *access_gauss(left, right, k, l);
					*access_gauss(left, right, k, l) = *access_gauss(left, right, r,l);
					*access_gauss(left, right, r, l) = tmp;
				}
				
			}
			for (int l = 0; l < rows; ++l)
			{
				if (l != r)
				{
					double a = *access_gauss(left, right, l, j);
					for (int m = 0; m < cols; ++m)
					{
						*access_gauss(left, right, l, m) -= *access_gauss(left, right, r, m) * a;
					}
				}
			}
		}
	}
}

static double	*access_gauss(t_mat4 *left, t_mat4 *right, int i, int j)
{
	if (j > 3)
		return (right->matrix + i * 4 + (j - 4));
	return (left->matrix + i * 4 + j);
}
