/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:56:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/09 19:10:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

double	get_closest_distance(double a, double b)
{
	if (a <= INACCURATE_ZERO && b <= INACCURATE_ZERO)
		return (-1);
	if (a <= INACCURATE_ZERO)
		return (b);
	if (b <= INACCURATE_ZERO)
		return (a);
	if (a < b)
		return (a);
	return (b);
}
