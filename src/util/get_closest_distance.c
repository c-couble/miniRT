/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:56:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/09 14:00:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

double	get_closest_distance(double a, double b, double max)
{
	if ((a <= INACCURATE_ZERO || a > max) && (b <= INACCURATE_ZERO || b > max))
		return (-1);
	if (a <= INACCURATE_ZERO || a > max)
		return (b);
	if (b <= INACCURATE_ZERO || b > max)
		return (a);
	if (a < b)
		return (a);
	return (b);
}
