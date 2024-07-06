/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic_equation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:13:53 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/08 19:35:52 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_util.h"
#include <math.h>

void	solve_quadratic_equation(t_quadratic *q)
{
	double	root;

	q->delta = powl(q->b, 2) - (4 * q->a * q->c);
	if (q->delta >= 0)
	{
		root = sqrt(q->delta);
		q->r1 = (-q->b - root) / (2 * q->a);
		q->r2 = (-q->b + root) / (2 * q->a);
	}
}