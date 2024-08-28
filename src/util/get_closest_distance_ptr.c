/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_distance_ptr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:23:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:38:12 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int	get_closest_distance_ptr(double a, double b, double *out)
{
	if (a <= INACCURATE_ZERO && b <= INACCURATE_ZERO)
	{
		*out = -1;
		return (0);
	}
	if (a <= INACCURATE_ZERO)
	{
		*out = b;
		return (0);
	}
	if (b <= INACCURATE_ZERO)
	{
		*out = a;
		return (1);
	}
	if (a < b)
	{
		*out = a;
		return (1);
	}
	*out = b;
	return (0);
}
