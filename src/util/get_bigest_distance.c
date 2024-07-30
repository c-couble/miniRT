/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bigest_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:45:12 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/31 01:45:38 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

double	get_bigest_distance(double a, double b)
{
	if (a <= INACCURATE_ZERO && b <= INACCURATE_ZERO)
		return (-1);
	if (a <= INACCURATE_ZERO)
		return (b);
	if (b <= INACCURATE_ZERO)
		return (a);
	if (a < b)
		return (b);
	return (a);
}
