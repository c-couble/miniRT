/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 05:02:15 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:36:15 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_math.h"
#include "mat4.h"

static void		subtract_line(t_mat4 *left, t_mat4 *right, int r, int j);
static int		get_pivot(t_mat4 *left, t_mat4 *right, int r, int j);
static double	*access_gauss(t_mat4 *left, t_mat4 *right, int i, int j);
static void		gauss_reduction(t_mat4 *left, t_mat4 *right);

t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out)
{
	t_mat4	left;
	t_mat4	right;

	left = *mat;
	mat4_identity(&right);
	gauss_reduction(&left, &right);
	*out = right;
	return (out);
}

static void	gauss_reduction(t_mat4 *left, t_mat4 *right)
{
	int		j;
	int		k;
	int		r;
	double	value;

	r = -1;
	j = 0;
	while (j < 8)
	{
		k = get_pivot(left, right, r, j);
		if (k == -1)
			return ;
		if (*access_gauss(left, right, k, j) != 0)
		{
			++r;
			value = *access_gauss(left, right, k, j);
			divide_line(left, k, value);
			divide_line(right, k, value);
			swap_lines(left, r, k);
			swap_lines(right, r, k);
			subtract_line(left, right, r, j);
		}
		++j;
	}
}

static int	get_pivot(t_mat4 *left, t_mat4 *right, int r, int j)
{
	int		i;
	int		k;
	double	max;

	k = -1;
	max = -1;
	i = r + 1;
	while (i < 4)
	{
		if (ft_dabs(*access_gauss(left, right, i, j)) > max)
		{
			max = ft_dabs(*access_gauss(left, right, i, j));
			k = i;
		}
		++i;
	}
	return (k);
}

static double	*access_gauss(t_mat4 *left, t_mat4 *right, int i, int j)
{
	if (j > 3)
		return (right->matrix + i * 4 + (j - 4));
	return (left->matrix + i * 4 + j);
}

static void	subtract_line(t_mat4 *left, t_mat4 *right, int r, int j)
{
	int		i;
	int		l;
	double	a;
	double	b;

	i = 0;
	while (i < 4)
	{
		if (i != r)
		{
			a = *access_gauss(left, right, i, j);
			l = 0;
			while (l < 8)
			{
				b = *access_gauss(left, right, r, l) * a;
				*access_gauss(left, right, i, l) -= b;
				++l;
			}
		}
		++i;
	}
}
