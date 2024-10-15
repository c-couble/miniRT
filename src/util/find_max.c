/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:10:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:11:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <sys/types.h>

double	find_max(double *arr, size_t size)
{
	size_t	i;
	double	max;

	i = 0;
	max = -DBL_MAX;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		++i;
	}
	return (max);
}
