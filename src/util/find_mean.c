/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:09:34 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:10:40 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

double	find_mean(double *arr, size_t size)
{
	size_t	i;
	double	sum;

	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += arr[i];
		++i;
	}
	return (sum / size);
}
