/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_gaussian_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:38:40 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:39:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

double	gaussian_kernel(double value)
{
	double	gaussian_point;

	gaussian_point = 1 / sqrt(2 * M_PI) * exp(-(value * value) / 2);
	return (gaussian_point);
}

double	*generate_gaussian_arr(size_t size, double mu)
{
	double *datas;
	datas = malloc(sizeof(double) * size);
	if (datas == NULL)
		return (NULL);

	for (int i = 0; (size_t)i < size ; ++i)
		datas[i] = gaussian_kernel((double)(i - ((double)size / 2)) / 19);
	(void)mu;
	return (datas);
}
