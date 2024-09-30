/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:04:23 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/01 03:06:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

double	rand_range(double min, double max)
{
	double	range;
	double	div;

	range = (max - min);
	div = RAND_MAX / range;
	return (min + (rand() / div));
}
