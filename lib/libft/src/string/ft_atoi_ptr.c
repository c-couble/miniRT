/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:44:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/13 20:46:18 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <limits.h>

int	ft_atoi_ptr(int *nbptr, const char *nptr)
{
	int	sign;

	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	*nbptr = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (*nbptr > (INT_MAX / 10) - (*nptr - '0'))
			return (-1);
		*nbptr = *nbptr * 10 + (*nptr - '0');
		++nptr;
	}
	if (*nptr)
		return (-1);
	*nbptr *= sign;
	return (0);
}
