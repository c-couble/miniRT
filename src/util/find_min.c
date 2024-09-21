/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:08:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:11:39 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <sys/types.h>

double	find_min(double *arr, size_t size)
{
	size_t	i;
	double	min;

	i = 0;
	min = DBL_MAX;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		++i;
	}
	return (min);
}
